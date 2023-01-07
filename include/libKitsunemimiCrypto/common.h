/**
 *  @file       common.h
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#ifndef CRYPTO_COMMON_H
#define CRYPTO_COMMON_H

#include <string>

namespace Kitsunemimi
{
struct DataBuffer;

//--------------------------------------------------------------------------------------------------
// HEX
//--------------------------------------------------------------------------------------------------
void hexEncode(std::string &result,
               const void* data,
               const uint64_t dataSize);

//--------------------------------------------------------------------------------------------------
// BASE64
//--------------------------------------------------------------------------------------------------
void encodeBase64(std::string &output,
                  const void* data,
                  const uint64_t dataSize);
bool decodeBase64(DataBuffer &result,
                  const std::string &input);
bool decodeBase64(std::string &result,
                  const std::string &input);

bool base64ToBase64Url(std::string &base64);
bool base64UrlToBase64(std::string &base64Url);

} // namespace Kitsunemimi

#endif // CRYPTO_COMMON_H
