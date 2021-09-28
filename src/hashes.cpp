/**
 *  @file       hashes.cpp
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#include <libKitsunemimiCrypto/hashes.h>
#include <libKitsunemimiCrypto/common.h>

#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/sha.h>
#include <cryptopp/md5.h>

namespace Kitsunemimi
{
namespace Crypto
{

//--------------------------------------------------------------------------------------------------
// SHA256
//--------------------------------------------------------------------------------------------------

/**
 * @brief generateSha256
 * @param result
 * @param input
 */
void
generate_SHA_256(std::string &result,
               const std::string &input)
{
    generate_SHA_256(result, &input[0], input.size());
}

/**
 * @brief generateSha256
 * @param result
 * @param input
 * @param inputSize
 */
void
generate_SHA_256(std::string &result,
               const void* input,
               const uint64_t inputSize)
{
    // input MUST be cleared to avoid conflicts
    result.clear();

    CryptoPP::SHA256 hash;
    byte digest[CryptoPP::SHA256::DIGESTSIZE];

    hash.CalculateDigest(digest, (byte*)input, inputSize);
    hexEncode(result, digest, sizeof(digest));
}

//--------------------------------------------------------------------------------------------------
// MD5
//--------------------------------------------------------------------------------------------------

/**
 * @brief generateMd5
 * @param result
 * @param input
 */
void
generate_MD5(std::string &result,
            const std::string &input)
{
    generate_MD5(result, &input[0], input.size());
}

/**
 * @brief generateMd5
 * @param result
 * @param input
 * @param inputSize
 */
void
generate_MD5(std::string &result,
            const void* input,
            const uint64_t inputSize)
{
    // input MUST be cleared to avoid conflicts
    result.clear();

    CryptoPP::MD5 hash;
    byte digest[CryptoPP::MD5::DIGESTSIZE];

    hash.CalculateDigest(digest, (byte*)input, inputSize);
    hexEncode(result, digest, sizeof(digest));
}

}
}
