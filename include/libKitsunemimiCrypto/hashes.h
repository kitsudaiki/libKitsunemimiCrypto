/**
 *  @file       hashes.h
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#ifndef HASHES_H
#define HASHES_H

#include <iostream>
#include <vector>

namespace Kitsunemimi
{
namespace Crypto
{

//--------------------------------------------------------------------------------------------------
// SHA256
//--------------------------------------------------------------------------------------------------
void generate_SHA_256(std::string &result,
                      const std::string &input);

void generate_SHA_256(std::string &result,
                      const void* input,
                      const uint64_t inputSize);

//--------------------------------------------------------------------------------------------------
// MD5
//--------------------------------------------------------------------------------------------------
void generate_MD5(std::string &result,
                  const std::string &input);

void generate_MD5(std::string &result,
                  const void* input,
                  const uint64_t inputSize);
}
}

#endif // HASHES_H
