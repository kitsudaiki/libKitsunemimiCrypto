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

//--------------------------------------------------------------------------------------------------
// SHA256
//--------------------------------------------------------------------------------------------------
bool generate_SHA_256(std::string &result,
                      const std::string &input);

bool generate_SHA_256(std::string &result,
                      const void* input,
                      const uint64_t inputSize);

} // namespace Kitsunemimi

#endif // HASHES_H
