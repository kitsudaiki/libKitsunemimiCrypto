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

#include <libKitsunemimiCommon/methods/string_methods.h>

namespace Kitsunemimi
{

//--------------------------------------------------------------------------------------------------
// SHA256
//--------------------------------------------------------------------------------------------------

/**
 * @brief generate SHA256 hash
 *
 * @param result reference for the resulting string
 * @param input input-string to hash
 *
 * @return false, if input is empty-string, else true
 */
bool
generate_SHA_256(std::string &result,
                 const std::string &input)
{
    return generate_SHA_256(result, &input[0], input.size());
}

/**
 * @brief generate SHA256 hash
 *
 * @param result reference for the resulting string
 * @param input pointer to the input-data
 * @param inputSize size of input-data in number of bytes
 *
 * @return false, if input is invalid, else true
 */
bool
generate_SHA_256(std::string &result,
                 const void* input,
                 const uint64_t inputSize)
{
    if(input == nullptr
            || inputSize == 0)
    {
        return false;
    }

    // input MUST be cleared to avoid conflicts
    result.clear();

    CryptoPP::SHA256 hash;
    CryptoPP::byte digest[CryptoPP::SHA256::DIGESTSIZE];

    hash.CalculateDigest(digest, (CryptoPP::byte*)input, inputSize);
    hexEncode(result, digest, sizeof(digest));
    Kitsunemimi::toLowerCase(result);

    return true;
}

} // namespace Kitsunemimi
