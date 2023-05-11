//
// Created by Zakaria on 13/12/2022.
//
#include <Oware.hpp>
#include <gtest/gtest.h>

namespace oware::test {
namespace {
    using Oware = oware::Oware;
    using House = oware::House;
    using interface::BoardType;
    class OwareTest : public ::testing::Test {
    protected:
        OwareTest() = default;

        void SetUp() override
        {
            oware = Oware();
        }
        Oware oware;
    };

    TEST_F(OwareTest, printBoardTest)
    {
        ASSERT_NO_THROW(oware.printBoard());
    }

    TEST_F(OwareTest, boardTest)
    {
        auto board = oware.getBoard();
        BoardType expectedResult{{{4, 4, 4, 4, 4, 4},
                                  {4, 4, 4, 4, 4, 4}}};

        ASSERT_EQ(expectedResult, board);
    }

    TEST_F(OwareTest, wrongBoardTest)
    {
        auto board = oware.getBoard();
        BoardType expectedResult{{{4, 1, 4, 4, 4, 4},
                                  {4, 4, 4, 3, 4, 4}}};

        ASSERT_NE(expectedResult, board);
    }

    TEST_F(OwareTest, sow01Test)
    {
        House house2Move{0, 1};
        const std::vector<House> expectedAffectedHouses = {{0, 0},
                                                           {1, 0},
                                                           {1, 1},
                                                           {1, 2}};
        const BoardType expectedResult{{{5, 0, 4, 4, 4, 4},
                                        {5, 5, 5, 4, 4, 4}}};

        auto affectedHouses = oware.sow(house2Move);
        std::cout << "sow: " << house2Move << oware;

        ASSERT_EQ(expectedAffectedHouses, affectedHouses);

        auto board = oware.getBoard();

        ASSERT_EQ(expectedResult, board);
    }

    TEST_F(OwareTest, sow05Test)
    {
        House house2Move{0, 5};
        const std::vector<House> expectedAffectedHouses = {{0, 4},
                                                           {0, 3},
                                                           {0, 2},
                                                           {0, 1}};
        const BoardType expectedResult{{{4, 5, 5, 5, 5, 0},
                                        {4, 4, 4, 4, 4, 4}}};

        auto affectedHouses = oware.sow(house2Move);
        std::cout << "sow: " << house2Move << oware;

        ASSERT_EQ(expectedAffectedHouses, affectedHouses);

        auto board = oware.getBoard();

        ASSERT_EQ(expectedResult, board);
    }

    TEST_F(OwareTest, sow10Test)
    {
        const House house2Move{1, 0};
        const std::vector<House> expectedAfectedHouses = {{1, 1},
                                                          {1, 2},
                                                          {1, 3},
                                                          {1, 4}};
        const BoardType expectedResult{{{4, 4, 4, 4, 4, 4},
                                        {0, 5, 5, 5, 5, 4}}};

        auto affectedHouses = oware.sow(house2Move);
        std::cout << "sow: " << house2Move << oware;

        ASSERT_EQ(expectedAfectedHouses, affectedHouses);

        auto board = oware.getBoard();
        ASSERT_EQ(expectedResult, board);
    }

    TEST_F(OwareTest, sow14Test)
    {
        House house2Move{1, 4};
        const std::vector<House> expectedAffectedHouses = {{1, 5},
                                                           {0, 5},
                                                           {0, 4},
                                                           {0, 3}};
        const BoardType expectedResult{{{4, 4, 4, 5, 5, 5},
                                        {4, 4, 4, 4, 0, 5}}};

        auto affectedHouses = oware.sow(house2Move);
        std::cout << "sow: " << house2Move << oware;

        ASSERT_EQ(expectedAffectedHouses, affectedHouses);

        auto board = oware.getBoard();

        ASSERT_EQ(expectedResult, board);
    }

    TEST_F(OwareTest, sow14_02Test)
    {

        std::vector<House> expectedAffectedHouses = {{1, 5},
                                                     {0, 5},
                                                     {0, 4},
                                                     {0, 3}};
        const BoardType expectedResult{{{5, 5, 0, 5, 6, 6},
                                        {5, 5, 4, 0, 1, 6}}};
        //sow 1
        House house2Move{1, 4};
        auto affectedHouses = oware.sow(house2Move);
        std::cout << "sow1: " << house2Move << oware;
        ASSERT_EQ(expectedAffectedHouses, affectedHouses);

        //sow 2
        house2Move = {0, 2};
        expectedAffectedHouses = {{0, 1},
                                  {0, 0},
                                  {1, 0},
                                  {1, 1}};
        affectedHouses = oware.sow(house2Move);
        std::cout << "sow2: " << house2Move << oware;
        ASSERT_EQ(expectedAffectedHouses, affectedHouses);

        //sow 3
        house2Move = {1, 3};
        expectedAffectedHouses = {{1, 4},
                                  {1, 5},
                                  {0, 5},
                                  {0, 4}};
        affectedHouses = oware.sow(house2Move);
        std::cout << "sow2: " << house2Move << oware;
        ASSERT_EQ(expectedAffectedHouses, affectedHouses);

        auto board = oware.getBoard();

        ASSERT_EQ(expectedResult, board);
    }

    TEST_F(OwareTest, sowOverSelectedTest)
    {
        House house2Move{1, 4};
        oware.setSeedsAt(house2Move, 14);

        const BoardType expectedResult{{{5, 5, 5, 5, 6, 6},
                                        {5, 5, 5, 5, 0, 6}}};

        auto affectedHouses = oware.sow(house2Move);
        std::cout << "sow: " << house2Move << oware;

        auto board = oware.getBoard();

        ASSERT_EQ(expectedResult, board);
    }

    TEST_F(OwareTest, wontest)
    {
        auto seed2Fill = 3;
        std::vector<House> affectedHouses = {{0, 5},
                                             {0, 4},
                                             {0, 3},
                                             {0, 2}};
        for (const auto &house: affectedHouses)
        {
            oware.setSeedsAt(house, seed2Fill);
        }

        std::cout << oware;
        auto wonSeeds = oware.wonSeeds(Player{Player::ID::PLAYER_B}, affectedHouses);
        ASSERT_EQ(affectedHouses.size() * seed2Fill, wonSeeds.first);
    }

    TEST_F(OwareTest, won2test)
    {
        auto seed2Fill = 3;
        std::vector<House> affectedHouses = {{0, 5},
                                             {0, 4},
                                             {0, 3},
                                             {0, 2}};
        for (const auto &house: affectedHouses)
        {
            oware.setSeedsAt(house, seed2Fill);
        }

        oware.setSeedsAt(affectedHouses[1], 4);

        std::cout << oware;
        Player player{Player::ID::PLAYER_B};
        auto wonSeeds = oware.wonSeeds(player, affectedHouses);
        ASSERT_EQ(6, wonSeeds.first);
    }
    TEST_F(OwareTest, wonSeedFailedHeadTest)
    {
        auto seed2Fill = 3;
        std::vector<House> affectedHouses = {{0, 5},
                                             {0, 4},
                                             {0, 3},
                                             {0, 2}};
        for (const auto &house: affectedHouses)
        {
            oware.setSeedsAt(house, seed2Fill);
        }

        oware.setSeedsAt(affectedHouses[3], 1);

        std::cout << oware;
        auto wonSeeds = oware.wonSeeds(Player{Player::ID::PLAYER_B}, affectedHouses);
        ASSERT_EQ(0, wonSeeds.first);
    }

}// namespace
}// namespace oware::test
