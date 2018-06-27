// Copyright (c) 2018 Slawek Mozdzonek
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DATAUTILS_H
#define DATAUTILS_H

#include <string>
#include <vector>

#include <univalue.h>
#include <wallet/fees.h>

void hex2ascii(const std::string& in, std::string& out);
std::string byte2str(const unsigned char* binaryData, size_t size);
void hex2bin(std::vector<char>& binaryData, const std::string& hexstr);
void hex2bin(std::vector<unsigned char>& binaryData, const std::string& hexstr);
std::string computeChange(const UniValue& inputs, double fee);
double computeFee(const CWallet& wallet, size_t dataSize);
std::string double2str(double val);
void reverseEndianess(std::string& str);

#endif
