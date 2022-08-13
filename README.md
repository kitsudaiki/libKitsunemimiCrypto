# libKitsunemimiCrypto

![Github workfloat status](https://img.shields.io/github/workflow/status/kitsudaiki/libKitsunemimiCrypto/build-and-test/develop?label=build%20and%20test&style=flat-square)
![GitHub tag (latest SemVer)](https://img.shields.io/github/v/tag/kitsudaiki/libKitsunemimiCrypto?label=version&style=flat-square)
![GitHub](https://img.shields.io/github/license/kitsudaiki/libKitsunemimiCrypto?style=flat-square)
![C++Version](https://img.shields.io/badge/c%2B%2B-17-blue?style=flat-square)
![Platform](https://img.shields.io/badge/platform-Linux--x64-lightgrey?style=flat-square)

## Description

Wrapper-library for crypto-operation from other external libraries, to simplify the usage of basic operation.

Actual support for:

- base64 encode-decode
- AES-256-CBC encryption
- Sha256 
- HMAC

## Build

### Requirements

name | repository | version | task
--- | --- | --- | ---
g++ | g++ | >= 8.0 | Compiler for the C++ code.
make | make | >= 4.0 | process the make-file, which is created by qmake to build the programm with g++
qmake | qt5-qmake | >= 5.0 | This package provides the tool qmake, which is similar to cmake and create the make-file for compilation.
ssl library | libssl-dev | >= 1.1.1f | provides signing-functions
crpyto++ | libcrypto++-dev | >= 8.4 | provides encryption-functions like AES

**IMPORTANT**: works also with OpenSSL 3.0, but with a bunch of compiler-warnings for the HMAC-functions. This will be solved later


Installation on Ubuntu/Debian:

```bash
sudo apt-get install g++ make qt5-qmake libssl-dev libcrypto++-dev 
```

IMPORTANT: All my projects are only tested on Linux. 

### Kitsunemimi-repositories

Repository-Name | Version-Tag | Download-Path
--- | --- | ---
libKitsunemimiCommon | v0.27.0 |  https://github.com/kitsudaiki/libKitsunemimiCommon.git

HINT: These Kitsunemimi-Libraries will be downloaded and build automatically with the build-script below.

### build library

In all of my repositories you will find a `build.sh`. You only have to run this script. It doesn't required sudo, because you have to install required tool via apt, for example, by yourself. But if other projects from me are required, it download them from github and build them in the correct version too. This script is also use by the ci-pipeline, so its tested with every commit.


Run the following commands:

```
git clone https://github.com/kitsudaiki/libKitsunemimiCrypto.git
cd libKitsunemimiCrypto
./build.sh
cd ../result
```

It create automatic a `build` and `result` directory in the directory, where you have cloned the project. At first it build all into the `build`-directory and after all build-steps are finished, it copy the include directory from the cloned repository and the build library into the `result`-directory. So you have all in one single place.

Tested on Debian and Ubuntu. If you use Centos, Arch, etc and the build-script fails on your machine, then please write me a mail and I will try to fix the script.


## Usage

### Base64

Example to encode and decode base64-strings:

```cpp
#include <libKitsunemimiCrypto/common.h>


// encode
std::string encodedStr = "";
const std::string input = "asdfasdfasdf123a";
Kitsunemimi::Crypto::encodeBase64(encodedStr, input.c_str(), input.size());
// encodedStr has now the content: "YXNkZmFzZGZhc2RmMTIzYQ=="


// decode
std::string decodedStr;
Kitsunemimi::Crypto::decodeBase64(decodedStr, encodedStr);
// decodedStr has now the content, which was the original input: "asdfasdfasdf123a"
// if the input was not a valid string, decodeBase64 return false
```


### AES-encryption

HINT: Actual only AES-CBC with 256-bit AES-key. Will be replaced by AES-XTS in the new future, but XTS was not supported in the version of the crpyto++ library, which I had when creating this library here.

Example for AES-CBC encyption and decryption:

```cpp
#include <libKitsunemimiCrypto/symmetric_encryption.h>

Kitsunemimi::ErrorContainer error;

// demo-string to encrypt
const std::string testData = "this is a test-string";

// create a key for the encryption and decryption. The key doesn't need to have 256 bit length,
// because the encryption and decrytion uses internally a sha-function to bring the key to a
// valid length. So you can use here any string you want.
CryptoPP::SecByteBlock key((unsigned char*)"asdf", 4);

// encrypt
std::string encryptionResult;
Kitsunemimi::Crypto::encrypt_AES_256_CBC(encryptionResult, testData, key, error);
// encryptionResult now contains the encrypted result

// decrypt
std::string decryptionResult;
Kitsunemimi::Crypto::decrypt_AES_256_CBC(decryptionResult, encryptionResult, key, error);
```

Both functions return `false`, if something went wrong. In this case the error-message can be converted to string with `error.toString()`.


### Sha256

Example for Sha256-hashing:

```cpp
#include <libKitsunemimiCrypto/hashes.h>

std::string input = "test";
std::string result = "";
Kitsunemimi::Crypto::generate_SHA_256(result, input);
// result now contains the string "9f86d081884c7d659a2feaa0c55ad015a3bf4f1b2b0b822cd15d6c15b0f00a08"


// the input doesn't have to be a string. You can also use a pointer to a byte-array like this
Kitsunemimi::Crypto::generate_SHA_256(result, input.c_str(), input.size());
```

### HMAC

Example to create an verify HMAC-strings

```cpp
#include <libKitsunemimiCrypto/signing.h>
#include <libKitsunemimiCrypto/common.h>

std::string testData = "this is a test-string";

// create key. Can have any length
CryptoPP::SecByteBlock key((unsigned char*)"asdf", 4);

// create HMAC from the testData by useing the key
std::string resultingHmac;
Kitsunemimi::Crypto::create_HMAC_SHA256(resultingHmac, testData, key)
// resultingHmac has now the content "58yA7QZ+I1opAOhoaWLwj4wnxUKz5xaYafjE+Vcb6c4="

// check if a string belongs to an HMAC-value
Kitsunemimi::Crypto::verify_HMAC_SHA256(testData, resultingHmac, key);
// returns true, if the resultingHmac together with the key match with the testData
```

## Contributing

Please give me as many inputs as possible: Bugs, bad code style, bad documentation and so on.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
