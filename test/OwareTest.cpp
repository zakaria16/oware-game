//
// Created by Zakaria on 13/12/2022.
//
#include <Oware.hpp>
#include <gtest/gtest.h>

namespace oware::test {
    namespace {
        using Oware = oware::Oware;
        using Hole = oware::Hole;

        class OwareTest : public ::testing::Test {
        protected:
            OwareTest() = default;

            void SetUp() override {
                oware = Oware();
            }
            Oware oware;
        };

        TEST_F(OwareTest, printBoardTest) {
            ASSERT_NO_THROW(oware.printBoard());
        }

        TEST_F(OwareTest, boardTest) {
            auto board = oware.getBoard();
            Oware::BoardType expectedResult{{{4, 4, 4, 4, 4, 4},
                                             {4, 4, 4, 4, 4, 4}}};

            ASSERT_EQ(expectedResult, board);
        }

        TEST_F(OwareTest, wrongBoardTest) {
            auto board = oware.getBoard();
            Oware::BoardType expectedResult{{{4, 1, 4, 4, 4, 4},
                                             {4, 4, 4, 3, 4, 4}}};

            ASSERT_NE(expectedResult, board);
        }

        TEST_F(OwareTest, move01Test) {
            Hole hole2Move{0, 1};
            const std::vector<Hole> expectedAffectedHoles = {{0, 0},
                                                             {1, 0},
                                                             {1, 1},
                                                             {1, 2}};
            const Oware::BoardType expectedResult{{{5, 0, 4, 4, 4, 4},
                                                   {5, 5, 5, 4, 4, 4}}};

            auto affectedHoles = oware.move(hole2Move);
            std::cout << "move: " << hole2Move << oware;

            ASSERT_EQ(expectedAffectedHoles, affectedHoles);

            auto board = oware.getBoard();

            ASSERT_EQ(expectedResult, board);
        }

        TEST_F(OwareTest, move05Test) {
            Hole hole2Move{0, 5};
            const std::vector<Hole> expectedAffectedHoles = {{0, 4},
                                                             {0, 3},
                                                             {0, 2},
                                                             {0, 1}};
            const Oware::BoardType expectedResult{{{4, 5, 5, 5, 5, 0},
                                                   {4, 4, 4, 4, 4, 4}}};

            auto affectedHoles = oware.move(hole2Move);
            std::cout << "move: " << hole2Move << oware;

            ASSERT_EQ(expectedAffectedHoles, affectedHoles);

            auto board = oware.getBoard();

            ASSERT_EQ(expectedResult, board);
        }

        TEST_F(OwareTest, move10Test) {
            const Hole hole2Move{1, 0};
            const std::vector<Hole> expectedAfectedHoles = {{1, 1},
                                                            {1, 2},
                                                            {1, 3},
                                                            {1, 4}};
            const Oware::BoardType expectedResult{{{4, 4, 4, 4, 4, 4},
                                                   {0, 5, 5, 5, 5, 4}}};

            auto affectedHoles = oware.move(hole2Move);
            std::cout << "move: " << hole2Move << oware;

            ASSERT_EQ(expectedAfectedHoles, affectedHoles);

            auto board = oware.getBoard();
            ASSERT_EQ(expectedResult, board);
        }

        TEST_F(OwareTest, move14Test) {
            Hole hole2Move{1, 4};
            const std::vector<Hole> expectedAffectedHoles = {{1, 5},
                                                             {0, 5},
                                                             {0, 4},
                                                             {0, 3}};
            const Oware::BoardType expectedResult{{{4, 4, 4, 5, 5, 5},
                                                   {4, 4, 4, 4, 0, 5}}};

            auto affectedHoles = oware.move(hole2Move);
            std::cout << "move: " << hole2Move << oware;

            ASSERT_EQ(expectedAffectedHoles, affectedHoles);

            auto board = oware.getBoard();

            ASSERT_EQ(expectedResult, board);
        }

        TEST_F(OwareTest, move14_02Test) {

            std::vector<Hole> expectedAffectedHoles = {{1, 5},
                                                       {0, 5},
                                                       {0, 4},
                                                       {0, 3}};
            const Oware::BoardType expectedResult{{{5, 5, 0, 5, 6, 6},
                                                   {5, 5, 4, 0, 1, 6}}};
            //move 1
            Hole hole2Move{1, 4};
            auto affectedHoles = oware.move(hole2Move);
            std::cout << "move1: " << hole2Move << oware;
            ASSERT_EQ(expectedAffectedHoles, affectedHoles);

            //move 2
            hole2Move = {0, 2};
            expectedAffectedHoles = {{0, 1},
                                     {0, 0},
                                     {1, 0},
                                     {1, 1}};
            affectedHoles = oware.move(hole2Move);
            std::cout << "move2: " << hole2Move << oware;
            ASSERT_EQ(expectedAffectedHoles, affectedHoles);

            //move 3
            hole2Move = {1, 3};
            expectedAffectedHoles = {{1, 4},
                                     {1, 5},
                                     {0, 5},
                                     {0, 4}};
            affectedHoles = oware.move(hole2Move);
            std::cout << "move2: " << hole2Move << oware;
            ASSERT_EQ(expectedAffectedHoles, affectedHoles);

            auto board = oware.getBoard();

            ASSERT_EQ(expectedResult, board);
        }

    }// namespace
}// namespace oware::test
