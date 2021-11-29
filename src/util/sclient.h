
#include "certs.h"

void initSSL() {
#if defined(ESP8266)
    sClient = new BearSSL::WiFiClientSecure();
    // mem hungry
    //BearSSL::X509List cert(cert_Cloudflare_Inc_ECC_CA_3);
    //sClient->setTrustAnchors(&cert);


    // reasonable
    sClient->setFingerprint(fingerprint_sni_cloudflaressl_com);

    //sClient->setInsecure();
#elif defined(ESP32)
    sClient = new WiFiClientSecure();
    sClient->setCACert(cert_Cloudflare_Inc_ECC_CA_3);

    //sClient->setInsecure();
#else
#endif
}

