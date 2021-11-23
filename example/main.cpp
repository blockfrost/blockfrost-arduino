#include <WiFi.h>
#include "creds.h"
#include "Blockfrost.h"

Blockfrost::CommonApi *comm;
Blockfrost::CardanoApi *cbapi;
Blockfrost::NutLinkApi *nlapi;

void setup(){
    Serial.begin(115200);

    Serial.print("Attempting to connect to SSID: ");
    Serial.println(WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    // attempt to connect to Wifi network:
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      // wait 1 second before re-trying
      delay(1000);
    }

    // Print LAN IP
    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());

    // Init SSL client
    initSSL();

    // Configure clock
    setClock();

    DEBUG_MSG("Free heap: %d\n\r", ESP.getFreeHeap());

    comm = new Blockfrost::CommonApi(sClient);
    comm->setToken(BLOCKFROST_TOKEN);
    cbapi = new Blockfrost::CardanoApi(sClient);
    cbapi->setToken(BLOCKFROST_TOKEN);
    nlapi = new Blockfrost::NutLinkApi(sClient);
    nlapi->setToken(BLOCKFROST_TESTNET_TOKEN);

    auto resp = comm->getHealth();
    Serial.printf("Health response code %d\n\r", resp.code);
    if(resp.obj.is_healthy) {
      Serial.printf("Healthy!\n\r");
    } else {
      Serial.printf("Not healthy!\n\r");
    }

    auto respRoot = comm->getRoot();
    Serial.printf("Root %s %s\n\r", respRoot.obj.url.c_str(), respRoot.obj.version.c_str());

    auto respClock = comm->getClock();
    Serial.printf("Clock %lld\n\r", respClock.obj.server_time);

    auto respMetrics = comm->getMetrics();
    Serial.printf("Usage\n\r");
    for(auto m : respMetrics.obj) {
      char buf[20];
      struct tm * timeinfo;
      timeinfo = localtime (&m.time);
      strftime(buf, sizeof(buf), "%b %d %H:%M", timeinfo);
      Serial.printf("- t: %s calls %d\n\r", buf, m.calls);
    }
}

void loop(){
    Blockfrost::Block block;

    {
      {
        auto resp = cbapi->getLatestBlock();
        if(resp.code == 200) {
          block = resp.obj;
          Serial.printf("Last block hash: %s\n\r", block.hash.c_str());
        } else {
          Serial.printf("Bad HTTP response code %d\n\r", resp.code);
        };
      }
    }

    {
      auto resp = cbapi->getLatestBlockTxs(5, 1, "desc");
      if(resp.code == 200) {
        auto txs = resp.obj;

        Serial.printf("Last txs: %d\n\r", txs.size());
        for(std::string tx : txs) {
          Serial.printf("- tx: %s\n\r", tx.c_str());
        }
      } else {
        Serial.printf("Bad HTTP response code %d\n\r", resp.code);
        Serial.printf("Message %s\n\r", resp.err.message.c_str());
      }
    }

    {
      auto resp = cbapi->getPreviousBlocks(block.hash);
      if(resp.code == 200) {
        auto prevBlocks = resp.obj;

        Serial.printf("Prev blocks: %d\n\r", prevBlocks.size());
        for(auto b : prevBlocks) {
          Serial.printf("- block: %s\n\r", b.hash.c_str());
        }
      } else {
        Serial.printf("Bad HTTP response code %d\n\r", resp.code);
      }
    }

    {
      auto resp = cbapi->getAccount("stake1u9fzg77vrgfqlplkjqe9hntdcvsurpvxd60yp2fhn73002qsv9pdk");
      if(resp.code == 200) {
        Serial.printf("Controlled amt: %s\n\r", resp.obj.controlled_amount.c_str());
      } else {
        Serial.printf("Bad HTTP response code %d\n\r", resp.code);
        Serial.printf("Error was %s\n\r", resp.err.message.c_str());
      }
    }

    {
      auto resp= cbapi->getAccountRewards("stake1u9fzg77vrgfqlplkjqe9hntdcvsurpvxd60yp2fhn73002qsv9pdk");
      if(resp.code == 200) {

        Serial.printf("Rewards\n\r");
        for(auto r : resp.obj) {
          Serial.printf("- epoch: %d - amount: %s\n\r", r.epoch, r.amount.c_str());
        }
      } else {
        Serial.printf("Bad HTTP response code %d\n\r", resp.code);
        Serial.printf("Error was %s\n\r", resp.err.message.c_str());
      }
    }

    // NutLink
    {
      auto resp = nlapi->nutlinkTickers("ADAUSD", 1, 1, "desc");
      if(resp.code == 200) {
        Serial.printf("NutLink tickers \n\r");
        for(auto x : resp.obj) {
          Serial.printf("- addr: %s, tx_hash: %s - block_height: %d - tx_index: %d\n\r"
              , x.address.c_str()
              , x.tx_hash.c_str()
              , x.block_height
              , x.tx_index
              );

          Serial.printf("- payload: %s\n\r", x.payload.dump().c_str());
        }
      } else {
        Serial.printf("Bad HTTP response code %d\n\r", resp.code);
        Serial.printf("Error was %s\n\r", resp.err.message.c_str());
      }
    }

    delay(60000);
}
