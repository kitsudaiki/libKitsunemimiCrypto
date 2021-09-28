/**
 *  @file       symmetric_encryption_test.cpp
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#include "symmetric_encryption_test.h"

#include <libKitsunemimiCrypto/symmetric_encryption.h>

namespace Kitsunemimi
{
namespace Crypto
{

Symmetric_Encryption_Test::Symmetric_Encryption_Test()
    : Kitsunemimi::CompareTestHelper("Symmetric_Encryption_Test")
{
    encrypt_decrypt_AES_256();
}

/**
 * @brief encrypt_decrypt_AES_256
 */
void
Symmetric_Encryption_Test::encrypt_decrypt_AES_256()
{
    const std::string testData = "this is a test-string";
    CryptoPP::SecByteBlock key((unsigned char*)"asdf", 4);
    std::string encryptionResult;
    std::string decryptionResult;

    TEST_EQUAL(Kitsunemimi::Crypto::encrypt_AES_256(encryptionResult, testData, key), true);
    TEST_EQUAL(Kitsunemimi::Crypto::decrypt_AES_256(decryptionResult, encryptionResult, key), true);

    TEST_NOT_EQUAL(encryptionResult, testData);
    TEST_EQUAL(decryptionResult, testData);
}

}
}
