/**
 *  @file       signing.h
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#ifndef SIGNING_H
#define SIGNING_H

#include <string>
#include <iostream>
#include <openssl/hmac.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/ec.h>
#include <cryptopp/aes.h>

namespace Kitsunemimi
{
namespace Crypto
{

//--------------------------------------------------------------------------------------------------
// HMAC
//--------------------------------------------------------------------------------------------------
bool create_HMAC_SHA256(std::string &result,
                        const std::string &input,
                        const CryptoPP::SecByteBlock &key);

bool verify_HMAC_SHA256(const std::string &input,
                        const std::string &hmac,
                        const CryptoPP::SecByteBlock &key);

} // namespace Crypto
} // namespace Kitsunemimi

#endif // SIGNING_H
