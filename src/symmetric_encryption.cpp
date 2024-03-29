/**
 *  @file       symatic_encryption.cpp
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#include <libKitsunemimiCrypto/symmetric_encryption.h>
#include <libKitsunemimiCommon/logger.h>

namespace Kitsunemimi
{

/**
 * @brief encrypt aes-256-cbc encrypted data
 *
 * @param result reference for the result of the encryption
 * @param input input to encrypt
 * @param key key for encryption
 * @param error reference for error-output
 *
 * @return false, if input is invaid, else true
 */
bool
encrypt_AES_256_CBC(std::string &result,
                    const std::string &input,
                    const CryptoPP::SecByteBlock &key,
                    ErrorContainer &error)
{
    // precheck
    if(key.size() == 0)
    {
        error.addMeesage("Provided key for AES-encryption is empty");
        return false;
    }
    if(input.size() == 0)
    {
        error.addMeesage("No data given for AES-encryption");
        return false;
    }

    // should never ever be differ, but its only to be save
    assert(2 * CryptoPP::AES::MAX_KEYLENGTH == CryptoPP::SHA512::DIGESTSIZE);

    // initialize key by hashing with sha512 to bring it to the correct length
    // sha512 is used to have 256 bytes for the key and 256 bytes for the initial vector
    CryptoPP::SecByteBlock sha512Key(2 * CryptoPP::AES::MAX_KEYLENGTH);
    CryptoPP::SHA512 hash;
    hash.CalculateDigest(&sha512Key[0], key.data(), key.size());

    // encrypt data
    CryptoPP::AES::Encryption aesEncryption(&sha512Key[0], CryptoPP::AES::MAX_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, &sha512Key[256]);
    CryptoPP::StringSink* stringSink = new CryptoPP::StringSink(result);
    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, stringSink);
    stfEncryptor.Put((CryptoPP::byte*)input.c_str(), input.size());
    stfEncryptor.MessageEnd();

    return true;
}

/**
 * @brief decrypt aes-256-cbc encrypted data
 *
 * @param result reference for the result of the decryption
 * @param input input to decrypt
 * @param key key for decryption
 * @param error reference for error-output
 *
 * @return false, if input is invaid, else true
 */
bool
decrypt_AES_256_CBC(std::string &result,
                    const std::string &input,
                    const CryptoPP::SecByteBlock &key,
                    ErrorContainer &error)
{
    // precheck
    if(key.size() == 0)
    {
        error.addMeesage("Provided key for AES-decryption is empty");
        return false;
    }
    if(input.size() == 0)
    {
        error.addMeesage("No data given for AES-decryption");
        return false;
    }

    // precheck
    if(input.size() % CryptoPP::AES::BLOCKSIZE != 0)
    {
        error.addMeesage("can not decrypt AES256, "
                         "because the mount of data has the a size of a multiple"
                         " of the blocksize " + std::to_string(CryptoPP::AES::BLOCKSIZE));
        error.addSolution("data are broken or not an AES 256 encrypted string");
        return false;
    }

    // should never ever be differ, but its only to be save
    assert(2 * CryptoPP::AES::MAX_KEYLENGTH == CryptoPP::SHA512::DIGESTSIZE);

    // initialize key by hashing with sha512 to bring it to the correct length
    // sha512 is used to have 256 bytes for the key and 256 bytes for the initial vector
    CryptoPP::SecByteBlock sha512Key(2 * CryptoPP::AES::MAX_KEYLENGTH);
    CryptoPP::SHA512 hash;
    hash.CalculateDigest(&sha512Key[0], key.data(), key.size());

    // decrypt data
    CryptoPP::AES::Decryption aesDecryption(&sha512Key[0], CryptoPP::AES::MAX_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, &sha512Key[256]);
    CryptoPP::StringSink* stringSink = new CryptoPP::StringSink(result);
    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, stringSink);
    stfDecryptor.Put((CryptoPP::byte*)input.c_str(), input.size());
    stfDecryptor.MessageEnd();

    return true;
}

} // namespace Kitsunemimi
