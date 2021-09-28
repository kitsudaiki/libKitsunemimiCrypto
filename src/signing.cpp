/**
 *  @file       signing.cpp
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#include <libKitsunemimiCrypto/signing.h>
#include <libKitsunemimiCrypto/common.h>

namespace Kitsunemimi
{
namespace Crypto
{

/**
 * @brief createHMAC
 * @param result
 * @param input
 * @param key
 * @return
 */
bool
create_HMAC_Sha256(std::string &result,
                   const std::string &input,
                   const CryptoPP::SecByteBlock &key)
{
    // calculate hmac signature
    unsigned int len = 32;
    unsigned char hmacResult[len];

    HMAC_CTX* ctx = HMAC_CTX_new();
    HMAC_Init_ex(ctx,
                 key.data(),
                 key.size(),
                 EVP_sha256(),
                 nullptr);
    HMAC_Update(ctx, (unsigned char*)input.c_str(), input.length());
    HMAC_Final(ctx, hmacResult, &len);
    HMAC_CTX_free(ctx);

    result = std::string((char*)hmacResult, len);
    Kitsunemimi::Crypto::encodeBase64(result, result.c_str(), sizeof(result));

    return true;
}

/**
 * @brief verifyHMAC
 * @param input
 * @param key
 * @return
 */
bool
verify_HMAC_Sha256(const std::string &input,
                   const std::string &hmac,
                   const CryptoPP::SecByteBlock &key)
{
    std::string compareHmac;
    create_HMAC_Sha256(compareHmac, input, key);  // TODO: handle result

    const bool result = hmac.size() == compareHmac.size()
                        && CRYPTO_memcmp(hmac.c_str(), compareHmac.c_str(), hmac.size()) == 0;

    return result;
}

}
}

