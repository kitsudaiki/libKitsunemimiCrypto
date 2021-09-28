/**
 *  @file       symatic_encryption.h
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#ifndef SYMMETRIC_ENCRYPTION_H
#define SYMMETRIC_ENCRYPTION_H

#include <iostream>
#include <libKitsunemimiCommon/buffer/data_buffer.h>

#include <cryptopp/sha.h>
#include <cryptopp/aes.h>
#include <cryptopp/files.h>
#include <cryptopp/modes.h>

namespace Kitsunemimi
{
namespace Crypto
{

//--------------------------------------------------------------------------------------------------
// AES256
//--------------------------------------------------------------------------------------------------
bool encrypt_AES_256(std::string &result,
                     const std::string &input,
                     const CryptoPP::SecByteBlock &key);

bool decrypt_AES_256(std::string &result,
                     const std::string &input,
                     const CryptoPP::SecByteBlock &key);

}
}

#endif // SYMMETRIC_ENCRYPTION_H
