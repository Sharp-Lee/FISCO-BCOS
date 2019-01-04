/**
 * @CopyRight:
 * FISCO-BCOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FISCO-BCOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with FISCO-BCOS.  If not, see <http://www.gnu.org/licenses/>
 * (c) 2016-2018 fisco-dev contributors.
 *
 * @file RpcFace.cpp
 * @author: caryliao
 * @date 2018-10-26
 */
#pragma once

#include "ModularServer.h"

namespace dev
{
namespace rpc
{
class RpcFace : public ServerInterface<RpcFace>
{
public:
    RpcFace()
    {
        this->bindAndAddMethod(jsonrpc::Procedure("getSystemConfigByKey",
                                   jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",
                                   jsonrpc::JSON_INTEGER, "param2", jsonrpc::JSON_STRING, NULL),
            &dev::rpc::RpcFace::getSystemConfigByKeyI);
        this->bindAndAddMethod(jsonrpc::Procedure("getBlockNumber", jsonrpc::PARAMS_BY_POSITION,
                                   jsonrpc::JSON_STRING, "param1", jsonrpc::JSON_INTEGER, NULL),
            &dev::rpc::RpcFace::getBlockNumberI);
        this->bindAndAddMethod(jsonrpc::Procedure("getPbftView", jsonrpc::PARAMS_BY_POSITION,
                                   jsonrpc::JSON_STRING, "param1", jsonrpc::JSON_INTEGER, NULL),
            &dev::rpc::RpcFace::getPbftViewI);
        this->bindAndAddMethod(jsonrpc::Procedure("getMinerList", jsonrpc::PARAMS_BY_POSITION,
                                   jsonrpc::JSON_STRING, "param1", jsonrpc::JSON_INTEGER, NULL),
            &dev::rpc::RpcFace::getMinerListI);
        this->bindAndAddMethod(jsonrpc::Procedure("getObserverList", jsonrpc::PARAMS_BY_POSITION,
                                   jsonrpc::JSON_STRING, "param1", jsonrpc::JSON_INTEGER, NULL),
            &dev::rpc::RpcFace::getObserverListI);
        this->bindAndAddMethod(jsonrpc::Procedure("getConsensusStatus", jsonrpc::PARAMS_BY_POSITION,
                                   jsonrpc::JSON_OBJECT, "param1", jsonrpc::JSON_INTEGER, NULL),
            &dev::rpc::RpcFace::getConsensusStatusI);

        this->bindAndAddMethod(jsonrpc::Procedure("getSyncStatus", jsonrpc::PARAMS_BY_POSITION,
                                   jsonrpc::JSON_OBJECT, "param1", jsonrpc::JSON_INTEGER, NULL),
            &dev::rpc::RpcFace::getSyncStatusI);

        this->bindAndAddMethod(jsonrpc::Procedure("getClientVersion", jsonrpc::PARAMS_BY_POSITION,
                                   jsonrpc::JSON_STRING, NULL),
            &dev::rpc::RpcFace::getClientVersionI);
        this->bindAndAddMethod(
            jsonrpc::Procedure("getPeers", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, NULL),
            &dev::rpc::RpcFace::getPeersI);
        this->bindAndAddMethod(jsonrpc::Procedure("getGroupPeers", jsonrpc::PARAMS_BY_POSITION,
                                   jsonrpc::JSON_OBJECT, "param1", jsonrpc::JSON_INTEGER, NULL),
            &dev::rpc::RpcFace::getGroupPeersI);
        this->bindAndAddMethod(jsonrpc::Procedure("getGroupList", jsonrpc::PARAMS_BY_POSITION,
                                   jsonrpc::JSON_OBJECT, NULL),
            &dev::rpc::RpcFace::getGroupListI);

        this->bindAndAddMethod(jsonrpc::Procedure("getBlockByHash", jsonrpc::PARAMS_BY_POSITION,
                                   jsonrpc::JSON_OBJECT, "param1", jsonrpc::JSON_INTEGER, "param2",
                                   jsonrpc::JSON_STRING, "param3", jsonrpc::JSON_BOOLEAN, NULL),
            &dev::rpc::RpcFace::getBlockByHashI);
        this->bindAndAddMethod(jsonrpc::Procedure("getBlockByNumber", jsonrpc::PARAMS_BY_POSITION,
                                   jsonrpc::JSON_OBJECT, "param1", jsonrpc::JSON_INTEGER, "param2",
                                   jsonrpc::JSON_STRING, "param3", jsonrpc::JSON_BOOLEAN, NULL),
            &dev::rpc::RpcFace::getBlockByNumberI);
        this->bindAndAddMethod(jsonrpc::Procedure("getBlockHashByNumber",
                                   jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",
                                   jsonrpc::JSON_INTEGER, "param2", jsonrpc::JSON_STRING, NULL),
            &dev::rpc::RpcFace::getBlockHashByNumberI);

        this->bindAndAddMethod(jsonrpc::Procedure("getTransactionByHash",
                                   jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",
                                   jsonrpc::JSON_INTEGER, "param2", jsonrpc::JSON_STRING, NULL),
            &dev::rpc::RpcFace::getTransactionByHashI);
        this->bindAndAddMethod(
            jsonrpc::Procedure("getTransactionByBlockHashAndIndex", jsonrpc::PARAMS_BY_POSITION,
                jsonrpc::JSON_OBJECT, "param1", jsonrpc::JSON_INTEGER, "param2",
                jsonrpc::JSON_STRING, "param3", jsonrpc::JSON_STRING, NULL),
            &dev::rpc::RpcFace::getTransactionByBlockHashAndIndexI);
        this->bindAndAddMethod(
            jsonrpc::Procedure("getTransactionByBlockNumberAndIndex", jsonrpc::PARAMS_BY_POSITION,
                jsonrpc::JSON_OBJECT, "param1", jsonrpc::JSON_INTEGER, "param2",
                jsonrpc::JSON_STRING, "param3", jsonrpc::JSON_STRING, NULL),
            &dev::rpc::RpcFace::getTransactionByBlockNumberAndIndexI);
        this->bindAndAddMethod(jsonrpc::Procedure("getTransactionReceipt",
                                   jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",
                                   jsonrpc::JSON_INTEGER, "param2", jsonrpc::JSON_STRING, NULL),
            &dev::rpc::RpcFace::getTransactionReceiptI);
        this->bindAndAddMethod(
            jsonrpc::Procedure("getPendingTransactions", jsonrpc::PARAMS_BY_POSITION,
                jsonrpc::JSON_OBJECT, "param1", jsonrpc::JSON_INTEGER, NULL),
            &dev::rpc::RpcFace::getPendingTransactionsI);
        this->bindAndAddMethod(
            jsonrpc::Procedure("call", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT, "param1",
                jsonrpc::JSON_INTEGER, "param2", jsonrpc::JSON_OBJECT, NULL),
            &dev::rpc::RpcFace::callI);

        this->bindAndAddMethod(jsonrpc::Procedure("sendRawTransaction", jsonrpc::PARAMS_BY_POSITION,
                                   jsonrpc::JSON_OBJECT, "param1", jsonrpc::JSON_INTEGER, "param2",
                                   jsonrpc::JSON_STRING, NULL),
            &dev::rpc::RpcFace::sendRawTransactionI);

        this->bindAndAddMethod(
            jsonrpc::Procedure("getCode", jsonrpc::PARAMS_BY_POSITION, jsonrpc::JSON_OBJECT,
                "param1", jsonrpc::JSON_INTEGER, "param2", jsonrpc::JSON_STRING, NULL),
            &dev::rpc::RpcFace::getCodeI);
        this->bindAndAddMethod(
            jsonrpc::Procedure("getTotalTransactionCount", jsonrpc::PARAMS_BY_POSITION,
                jsonrpc::JSON_OBJECT, "param1", jsonrpc::JSON_INTEGER, NULL),
            &dev::rpc::RpcFace::getTotalTransactionCountI);
    }

    inline virtual void getSystemConfigByKeyI(const Json::Value& request, Json::Value& response)
    {
        response = this->getSystemConfigByKey(request[0u].asInt(), request[1u].asString());
    }
    inline virtual void getBlockNumberI(const Json::Value& request, Json::Value& response)
    {
        response = this->getBlockNumber(request[0u].asInt());
    }
    inline virtual void getPbftViewI(const Json::Value& request, Json::Value& response)
    {
        response = this->getPbftView(request[0u].asInt());
    }
    inline virtual void getMinerListI(const Json::Value& request, Json::Value& response)
    {
        response = this->getMinerList(request[0u].asInt());
    }
    inline virtual void getObserverListI(const Json::Value& request, Json::Value& response)
    {
        response = this->getObserverList(request[0u].asInt());
    }
    inline virtual void getConsensusStatusI(const Json::Value& request, Json::Value& response)
    {
        response = this->getConsensusStatus(request[0u].asInt());
    }

    inline virtual void getSyncStatusI(const Json::Value& request, Json::Value& response)
    {
        response = this->getSyncStatus(request[0u].asInt());
    }

    inline virtual void getClientVersionI(const Json::Value& request, Json::Value& response)
    {
        response = this->getClientVersion();
    }
    inline virtual void getPeersI(const Json::Value& request, Json::Value& response)
    {
        response = this->getPeers();
    }
    inline virtual void getGroupPeersI(const Json::Value& request, Json::Value& response)
    {
        response = this->getGroupPeers(request[0u].asInt());
    }
    inline virtual void getGroupListI(const Json::Value& request, Json::Value& response)
    {
        response = this->getGroupList();
    }

    inline virtual void getBlockByHashI(const Json::Value& request, Json::Value& response)
    {
        response =
            this->getBlockByHash(request[0u].asInt(), request[1u].asString(), request[2u].asBool());
    }
    inline virtual void getBlockByNumberI(const Json::Value& request, Json::Value& response)
    {
        response = this->getBlockByNumber(
            request[0u].asInt(), request[1u].asString(), request[2u].asBool());
    }
    inline virtual void getBlockHashByNumberI(const Json::Value& request, Json::Value& response)
    {
        response = this->getBlockHashByNumber(request[0u].asInt(), request[1u].asString());
    }

    inline virtual void getTransactionByHashI(const Json::Value& request, Json::Value& response)
    {
        response = this->getTransactionByHash(request[0u].asInt(), request[1u].asString());
    }
    inline virtual void getTransactionByBlockHashAndIndexI(
        const Json::Value& request, Json::Value& response)
    {
        response = this->getTransactionByBlockHashAndIndex(
            request[0u].asInt(), request[1u].asString(), request[2u].asString());
    }
    inline virtual void getTransactionByBlockNumberAndIndexI(
        const Json::Value& request, Json::Value& response)
    {
        response = this->getTransactionByBlockNumberAndIndex(
            request[0u].asInt(), request[1u].asString(), request[2u].asString());
    }
    inline virtual void getTransactionReceiptI(const Json::Value& request, Json::Value& response)
    {
        response = this->getTransactionReceipt(request[0u].asInt(), request[1u].asString());
    }
    inline virtual void getPendingTransactionsI(const Json::Value& request, Json::Value& response)
    {
        response = this->getPendingTransactions(request[0u].asInt());
    }
    inline virtual void getCodeI(const Json::Value& request, Json::Value& response)
    {
        response = this->getCode(request[0u].asInt(), request[1u].asString());
    }
    inline virtual void getTotalTransactionCountI(const Json::Value& request, Json::Value& response)
    {
        response = this->getTotalTransactionCount(request[0u].asInt());
    }
    inline virtual void callI(const Json::Value& request, Json::Value& response)
    {
        response = this->call(request[0u].asInt(), request[1u]);
    }
    inline virtual void sendRawTransactionI(const Json::Value& request, Json::Value& response)
    {
        response = this->sendRawTransaction(request[0u].asInt(), request[1u].asString());
    }

    // system config part
    virtual std::string getSystemConfigByKey(int param1, const std::string& param2) = 0;

    // consensus part
    virtual std::string getBlockNumber(int param1) = 0;
    virtual std::string getPbftView(int param1) = 0;
    virtual Json::Value getMinerList(int param1) = 0;
    virtual Json::Value getObserverList(int param1) = 0;
    virtual Json::Value getConsensusStatus(int param1) = 0;

    // sync part
    virtual Json::Value getSyncStatus(int param1) = 0;

    // p2p part
    virtual std::string getClientVersion() = 0;
    virtual Json::Value getPeers() = 0;
    virtual Json::Value getGroupPeers(int param1) = 0;
    virtual Json::Value getGroupList() = 0;

    // block part
    virtual Json::Value getBlockByHash(int param1, const std::string& param2, bool param3) = 0;
    virtual Json::Value getBlockByNumber(int param1, const std::string& param2, bool param3) = 0;
    virtual std::string getBlockHashByNumber(int param1, const std::string& param2) = 0;

    // transaction part
    /// @return the information about a transaction requested by transaction hash.
    virtual Json::Value getTransactionByHash(int param1, const std::string& param2) = 0;
    /// @return information about a transaction by block hash and transaction index position.
    virtual Json::Value getTransactionByBlockHashAndIndex(
        int param1, const std::string& param2, const std::string& param3) = 0;
    /// @return information about a transaction by block number and transaction index position.
    virtual Json::Value getTransactionByBlockNumberAndIndex(
        int param1, const std::string& param2, const std::string& param3) = 0;
    /// @return the receipt of a transaction by transaction hash.
    /// @note That the receipt is not available for pending transactions.
    virtual Json::Value getTransactionReceipt(int param1, const std::string& param2) = 0;
    /// @return information about getPendingTransactions.
    virtual Json::Value getPendingTransactions(int param1) = 0;
    /// Returns code at a given address.
    virtual std::string getCode(int param1, const std::string& param2) = 0;
    /// Returns the count of transactions and blocknumber.
    virtual Json::Value getTotalTransactionCount(int param1) = 0;
    /// Executes a new message call immediately without creating a transaction on the blockchain.
    virtual Json::Value call(int param1, const Json::Value& param2) = 0;
    /// Creates new message call transaction or a contract creation for signed transactions.
    virtual std::string sendRawTransaction(int param1, const std::string& param2) = 0;
};

}  // namespace rpc
}  // namespace dev