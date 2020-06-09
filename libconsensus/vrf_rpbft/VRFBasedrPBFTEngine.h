/*
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
 * (c) 2016-2020 fisco-dev contributors.
 */
/**
 * @brief : implementation of VRF based rPBFTEngine
 * @file: VRFBasedrPBFTEngine.h
 * @author: yujiechen
 * @date: 2020-06-04
 */
#pragma once
#include <libconsensus/rotating_pbft/RotatingPBFTEngine.h>


#define VRFRPBFTEngine_LOG(LEVEL) \
    LOG(LEVEL) << LOG_BADGE("CONSENSUS") << LOG_BADGE("VRFBasedrPBFTEngine")

namespace dev
{
namespace consensus
{
struct NodeRotatingInfo
{
    using Ptr = std::shared_ptr<NodeRotatingInfo>;
    u256 removedWorkingSealerNum;
    u256 insertedWorkingSealerNum;
};

class VRFBasedrPBFTEngine : public dev::consensus::RotatingPBFTEngine
{
public:
    using Ptr = std::shared_ptr<VRFBasedrPBFTEngine>;
    VRFBasedrPBFTEngine(dev::p2p::P2PInterface::Ptr _service,
        dev::txpool::TxPoolInterface::Ptr _txPool,
        dev::blockchain::BlockChainInterface::Ptr _blockChain,
        dev::sync::SyncInterface::Ptr _blockSync,
        dev::blockverifier::BlockVerifierInterface::Ptr _blockVerifier,
        dev::PROTOCOL_ID const& _protocolId, KeyPair const& _keyPair,
        h512s const& _sealerList = h512s())
      : RotatingPBFTEngine(_service, _txPool, _blockChain, _blockSync, _blockVerifier, _protocolId,
            _keyPair, _sealerList),
        m_nodeRotatingInfo(std::make_shared<NodeRotatingInfo>())
    {}

    bool shouldRotateSealers() { return m_shouldRotateSealers.load(); }
    void setShouldRotateSealers(bool _shouldRotateSealers);

    // Note: here must be
    NodeRotatingInfo nodeRotatingInfo()
    {
        ReadGuard l(x_nodeRotatingInfo);
        return *m_nodeRotatingInfo;
    }

protected:
    IDXTYPE minValidNodes() const override { return m_workingSealersNum.load() - m_f; }
    IDXTYPE selectLeader() const override;
    void updateConsensusNodeList() override;

    void resetConfig() override;
    void updateConsensusInfo() override;

private:
    void updateNodeRotatingInfo();

private:
    // Used to notify Sealer whether it needs to rotate sealers
    std::atomic_bool m_shouldRotateSealers = {false};
    std::atomic<int64_t> m_workingSealersNum = {0};

    std::shared_ptr<NodeRotatingInfo> m_nodeRotatingInfo;
    mutable SharedMutex x_nodeRotatingInfo;
};
}  // namespace consensus
}  // namespace dev