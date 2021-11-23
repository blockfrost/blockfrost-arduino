[![Made by Five Binaries](https://img.shields.io/badge/made%20by-Five%20Binaries-darkviolet.svg?style=flat-square)](https://fivebinaries.com/)

<img src="https://blockfrost.io/images/logo.svg" width="250" align="right" height="90">

# blockfrost-arduino

<br/>

<p align="center">Arduino SDK for <a href="https://blockfrost.io">Blockfrost.io</a> API.</p>
<p align="center">
  <a href="#about">About</a> •
  <a href="#getting-started">Getting started</a> •
  <a href="#installation">Installation</a> •
  <a href="#usage">Usage</a>
</p>

<br/>

## About

Arduino SDK for the Blockfrost.io API targeting ESP32 development boards.

## Getting started

To use this SDK, you first need to log in to [blockfrost.io](https://blockfrost.io), create your project and retrieve the API token.

<img src="https://i.imgur.com/smY12ro.png">

<br/>

## Installation

The SDK uses [platformio][https://platformio.org/].

You can either work directly with this repository or add this package as a dependency of your project using

```
lib_deps =
  https://github.com/blockfrost/blockfrost-arduino
```

To enter a development shell, use `nix-shell`.

## Usage

To build the [example](./example), copy `example/creds.h.sample`
to `example/creds.h` and fill in your credentials.

```sh
git clone https://github.com/blockfrost/blockfrost-arduino
cd blockfrost-arduino
cp example/creds.h.sample example/creds.h
# edit WiFi settings and Blockfrost tokens
# build
pio run
# upload
pio run --target upload
```
