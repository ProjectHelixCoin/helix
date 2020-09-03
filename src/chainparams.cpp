// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2017-2018 The Phore developers
// Copyright (c) 2018-2019 The Helix developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (     0, uint256("79a3c45d6e2760efb4d6de76d34b1f4833ba919bc114e1da0f671b1700a78f08"))
    (     1, uint256("6103a794040cd5c2a2dce252d49dc01b2e42358cb44bbd3089b040ea8437b25e"))
    (   500, uint256("000000000002576180e507670cbcc6f90110f450a09619969daca80db4c99db2"))
	(  1000, uint256("0000000000035895b91ae55236883f81cf3fcb62f0d6cadaf49a0eca7ef1e07b"))
	(  1500, uint256("000000000003c6df13062329c83d55f7e955912454d01dcae9ee03aaa254f303"))
	( 10000, uint256("000000000001cefb823e793c7c27ad4b74feb5990e7f68127a10ef59b9ab19c7"))
	( 20000, uint256("000000000000b74cbe73924535468a109d00a1d4fc49a7bdffb777c9924e725d"))
	( 30000, uint256("0000007b6ca741c608a844685480d1765dd1faa7f1c1fc66b780f5663a4d1caf"))
	( 35000, uint256("0000000000052f6cff8a74737729880fee2030984a2e4b815d8b8913d83a629a"))
	( 50000, uint256("000000000009cdaeb5cf0ef84355153aa38e942d750e6000d73d04a4ce4e6c9b"))
	( 75000, uint256("000000000011bc9bfb698c53359f569d92f090b84e814feb96ef00ddf16a0b56"))
	( 90000, uint256("000000000000e4573d249e86972aebf57ce377d7342d8bbba351c3f331588c4f"))
	( 90200, uint256("000000000011f7817fb286c514c71f094e1afe391aaa1a915d2631aa2005dd86"))	
	( 90200, uint256("000000000011f7817fb286c514c71f094e1afe391aaa1a915d2631aa2005dd86"))
	( 100000, uint256("0fd4901842a3b39ff9dab91afecbf3a9570ad8faf09100a57d539245826b99ca"))
	( 125000, uint256("1101e508fdf800468630a640b9f928ae21c3dc411bb5606b397bde75b1adaa1f"))
	( 150000, uint256("108aac50762723fe319931b12a063ffa08465e707db7f624f3b9d1fa446822b4"))
	( 175000, uint256("7523c1517f5727114cae1665725749c0dce341be7a3034192c98ec92c151ded9"))
	( 200000, uint256("25d5407abbca5b217bdebe143fbd06427980e46e14e516150d3c58b77e03ea91"))
	( 225000, uint256("80d9b4cd48aa963c58f364e987497ae6807a3be0b699812b51c1b743147d6fe0"))
	( 250000, uint256("5733cac18dfbad3a95b9343272bab90670b0df8b7ff7c0353249b9601002f64e"))
	( 262639, uint256("ead6534cc6ff592028f860a9bc17aa4aa0759de6261a534e4c87d2e91890aece"))
	( 272592, uint256("e99e96b15c27bf1178d124272f32b538890c30ff12548f59160d6e532ae84fad"))
	( 272593, uint256("22df09ced673750e5bcf6a6af3c1084e6393013a211f73ab66b6c41d86c39edb"))
	( 300000, uint256("903c79806c02cdecfd8b38caac2b85c4ceb274864796ed473f4408354c702642"))
	( 350000, uint256("95dba3af31b2eee5df3e5d4bc87c7860a523a0d1efaea9b5b590ad5f8bb9acea"))
	( 400000, uint256("f7f411e13a8559b82defd209611b659794ad59a2f10ef0e89630e990dedb5083"))
	( 425000, uint256("2902ce1f4eed59e3757bfb0116e7eeec6da4264b934ae02bb644235e41a58f3d"))
	( 450000, uint256("1a22f0fd98f1dd900108c8b5ede8de256dba79596bd781aa0dfb00bf4e2331fd"))
	( 500000, uint256("3f7e8645f8b40288ef94812ad64fb2b1b6f8d7c5006db521c2f6c4104552acd1"))
	( 550000, uint256("c86d2d309bbc461cb393958d2d6845fbc82438d73b04a9f5db7bf31a2cddbe1c"))
	( 600000, uint256("d18555608c63695084e8563e69440ea5f748f93837ff430e8254813bbadb1b66"))
	( 650000, uint256("0647bd41acf0c9defe91699ca3901ca7cf86be7f528c3fd26b14f9ce2531fd63"))
	( 700000, uint256("159dc1e73e968a793282f686a3408afe41c72c358019ccb9e22711a66fda77b9"))
	( 750000, uint256("80a663fb9a25eadb265fa6965f2ff7e6e6217dba9e7a7ff16cc389fe3348423f"))
	( 800000, uint256("a32bc7b377cc193eb438f5577165e793cf79aa517abe5582d801c6917a553e5a"))
	( 848572, uint256("a06305f5a6434a7837c6c9e540118a0b3aaca1de162a06bbfb3b6b1cf803306a"))	
	;

static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1552125921, // * UNIX timestamp of last checkpoint block
    446515,     // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    1440        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("9c5129f0b7e850d5ee54aceacff2df8086e57629debb8dc57b192ad089eb9b44"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    0,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("5f1f4acffb2b1f38dc3484ea642607e588f540d27ece5582c8c4991c67337b3b"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,

    0,

    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params() const
{
    assert(this);
    static CBigNum bnTrustedModulus;
    bnTrustedModulus.SetDec(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParams = libzerocoin::ZerocoinParams(bnTrustedModulus);

    return &ZCParams;
}

libzerocoin::ZerocoinParams* CChainParams::OldZerocoin_Params() const
{
    assert(this);
    static CBigNum bnTrustedModulus;
    bnTrustedModulus.SetHex(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParams = libzerocoin::ZerocoinParams(bnTrustedModulus);

    return &ZCParams;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x3b;
        pchMessageStart[1] = 0xe7;
        pchMessageStart[2] = 0x59;
        pchMessageStart[3] = 0xf0;
        vAlertPubKey = ParseHex("043747a78571fb1aaa306f9b51c03ab0bd39b7186f7c9c321adb7c50f7f2955c7f8254c530e134bd886ea8f8cfabe4bed01b25b7cd3245709cd2f7fd5e263c881a");
        nDefaultPort = 37415;
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // Helix: 1 day
        nTargetSpacing = 1 * 60;  // Helix: 1 minute
        nMaturity = 50;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 1000000000 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 90200;
        
        nModifierUpdateBlock = 0;
       
        nZerocoinStartHeight = 90201;

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         *
         * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
         *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
         *   vMerkleTree: e0028e
         */
        const char* pszTimestamp = "5 July 2018, the birth of Helix";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].SetEmpty();
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1531496589;
        genesis.nBits = 0x207fffff;;
        genesis.nNonce = 192840;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x79a3c45d6e2760efb4d6de76d34b1f4833ba919bc114e1da0f671b1700a78f08"));
        assert(genesis.hashMerkleRoot == uint256("0x210fa744202cef1c9248d9f82efadaa1387341e5c4b85b7a87ae56866514ef27"));

        vSeeds.push_back(CDNSSeedData("Seed1", "crazyseeder.helix-crypto.com"));
        vSeeds.push_back(CDNSSeedData("Seed2", "seed1.helix-crypto.com"));
        vSeeds.push_back(CDNSSeedData("Seed3", "seed2.helix-crypto.com"));
        vSeeds.push_back(CDNSSeedData("Seed4", "seed3.helix-crypto.com"));
        vSeeds.push_back(CDNSSeedData("Seed5", "seed4.helix-crypto.com"));
        vSeeds.push_back(CDNSSeedData("Seed6", "seed5.helix-crypto.com"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 40); // Testnet helix addresses start with 'H'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 13);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 212);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        nExtCoinType = 444;

        bech32_hrp = "ph";

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "046c4492a5b596c4ab60891dafef157a50d668b555989b8330fe2ec14a93993e50e306b0e63a561d4f5d225a34b1387735d47c9fe315795be6fdcfeb7ff06a73be";
        strObfuscationPoolDummyAddress = "HDw5WYmcSePwTxRZcDfzWmZnG3KNdtktgB";

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";

        nZerocoinLastOldParams = 99999999; // Updated to defer zerocoin v2 for further testing.
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nBudgetFeeConfirmations = 6; // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x4f;
        pchMessageStart[1] = 0x6c;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0x7a;
        vAlertPubKey = ParseHex("0462af22b469d8c12de76a033b81378b0c4c7694c19863b073f51b34476d5b39ba88769ab83e9e48389985fd838d41704449b9ece1fd36720b9116338b8fb30794");
        nDefaultPort = 37417;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // Helix: 1 day
        nTargetSpacing = 1 * 10;  // Helix: 1 minute
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 51197; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 43199500 * COIN;
        nLastPOWBlock = 90200;
        nZerocoinStartHeight = 90201;

        nZerocoinLastOldParams = 100000000;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1531496589;
        genesis.nNonce   = 192838;


        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x9c5129f0b7e850d5ee54aceacff2df8086e57629debb8dc57b192ad089eb9b44"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 127); // Testnet helix addresses start with 't'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet helix script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet helix BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet helix BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet phore BIP44 coin type is '1' (All coin's testnet default)
        nExtCoinType = 1;

        bech32_hrp = "tp";

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "04dcf81391f0d56b027add70054ab55e7bc978b925d4a88e572292e4bfe99c132dcbd91ca4fdf7239f6705aa5242ad9d0f81bb6add73bc91ffdcb57e61da2a201a"; 
        strObfuscationPoolDummyAddress = "";
        nBudgetFeeConfirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                     // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xe0;
        pchMessageStart[1] = 0x78;
        pchMessageStart[2] = 0x3a;
        pchMessageStart[3] = 0x40;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // Helix: 1 day
        nTargetSpacing = 1 * 60;        // Helix: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1531496589;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 192837;
        nMaturity = 0;
        nLastPOWBlock = 999999999; // PoS complicates Regtest because of timing issues
        nZerocoinLastOldParams = 499;
        nZerocoinStartHeight = 100;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 37417;

        assert(hashGenesisBlock == uint256("0x5f1f4acffb2b1f38dc3484ea642607e588f540d27ece5582c8c4991c67337b3b"));

        bech32_hrp = "hlixt";

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
        nRequiredAccumulation = 1;

        // {
        //     "PrivateKey": "923EhWh2bJHynX6d4Tqt2Q75bhTDCT1b4kff3qzDKDZHZ6pkQs7",
        //     "PublicKey": "04866dc02c998b7e1ab16fe14e0d86554595da90c36acb706a4d763b58ed0edb1f82c87e3ced065c5b299b26e12496956b9e5f9f19aa008b5c46229b15477c875a"
        // }
        strSporkKey = "04dcf81391f0d56b027add70054ab55e7bc978b925d4a88e572292e4bfe99c132dcbd91ca4fdf7239f6705aa5242ad9d0f81bb6add73bc91ffdcb57e61da2a201a";
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 37418;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        nExtCoinType = 1;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
