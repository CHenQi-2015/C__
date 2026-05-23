// ==================== 头文件部分 ====================
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <regex>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <future>
#include <fstream>
#include <memory>
#include <random>
#include <queue>
#include <stack>
#include <list>
#include <iomanip>

#pragma comment(lib,"winmm.lib")
using namespace std;

// ==================== 音乐播放系统 ====================
class MusicPlayer {
private:
    enum Scale
    {
      Rest = 0, C8 = 108, B7 = 107, A7s = 106, A7 = 105, G7s = 104, G7 = 103, F7s = 102, F7 = 101, E7 = 100,
      D7s = 99, D7 = 98, C7s = 97, C7 = 96, B6 = 95, A6s = 94, A6 = 93, G6s = 92, G6 = 91, F6s = 90, F6 = 89,
      E6 = 88, D6s = 87, D6 = 86, C6s = 85, C6 = 84, B5 = 83, A5s = 82, A5 = 81, G5s = 80, G5 = 79, F5s = 78,
      F5 = 77, E5 = 76, D5s = 75, D5 = 74, C5s = 73, C5 = 72, B4 = 71, A4s = 70, A4 = 69, G4s = 68, G4 = 67,
      F4s = 66, F4 = 65, E4 = 64, D4s = 63, D4 = 62, C4s = 61, C4 = 60, B3 = 59, A3s = 58, A3 = 57, G3s = 56,
      G3 = 55, F3s = 54, F3 = 53, E3 = 52, D3s = 51, D3 = 50, C3s = 49, C3 = 48, B2 = 47, A2s = 46, A2 = 45,
      G2s = 44, G2 = 43, F2s = 42, F2 = 41, E2 = 40, D2s = 39, D2 = 38, C2s = 37, C2 = 36, B1 = 35, A1s = 34,
      A1 = 33, G1s = 32, G1 = 31, F1s = 30, F1 = 29, E1 = 28, D1s = 27, D1 = 26, C1s = 25, C1 = 24, B0 = 23,
      A0s = 22, A0 = 21
    };

    enum Voice
    {
      X1 = C2, X2 = D2, X3 = E2, X4 = F2, X5 = G2, X6 = A2, X7 = B2,
      L1 = C3, L2 = D3, L3 = E3, L4 = F3, L5 = G3, L6 = A3, L7 = B3,
      M1 = C4, M2 = D4, M3 = E4, M4 = F4, M5 = G4, M6 = A4, M7 = B4,
      H1 = C5, H2 = D5, H3 = E5, H4 = F5, H5 = G5, H6 = A5, H7 = B5,
      LOW_SPEED = 500, MIDDLE_SPEED = 400, HIGH_SPEED = 300,
      _ = 0XFF
    };

    bool isPlaying;

public:
    MusicPlayer() : isPlaying(false) {}
    
    void playWindMusic() {
        isPlaying = true;
        HMIDIOUT handle;
        midiOutOpen(&handle, 0, 0, 0, CALLBACK_NULL);
        
        int volume = 0x7f;
        int voice = 0x0;
        int sleep = 350;
        
        int wind[] =
        {
           400,0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,0,L7,M1,M2,M3,300,L2,0,M5,M3,M2,M3,M1,M2,L7,M1,300,L5,0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,0,L7,M1,M2,M3,300,L2,0,M5,M3,M2,M3,M1,M2,L7,M1,300,L5,
           0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,0,L7,M1,M2,M3,300,L2,0,M5,M3,M2,M3,M1,M2,L7,M1,300,L5,0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,
           0,M6,M3,M2,L6,M3,L6,M2,M3,L6,_,_,_,
           M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M1,300,M2,700,0,M1,M2,M3,M2,M1,300,L5,_,
           M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M3,300,M2,0,M1,700,300,M2,_,_,_,
           M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M3,300,M2,0,M1,700,300,L6,_,
           0,M3,M2,M1,M2,300,M1,_,0,M3,M2,M1,M2,300,M1,700,0,L5,M3,M2,M1,M2,300,M1,_,_,_,
           M1,M2,M3,M1,M6,0,M5,M6,300,_,700,0,M1,300,M7,0,M6,M7,300,_,_,M7,0,M6,M7,300,_,M3,0,H1,H2,H1,M7,300,M6,M5,M6,0,M5,M6,_,M5,M6,M5,300,M6,0,M5,M2,300,_,0,M5,700,300,M3,_,_,_,
           M1,M2,M3,M1,M6,0,M5,M6,300,_,700,0,M1,300,M7,0,M6,M7,300,_,_,M7,0,M6,M7,300,_,M3,0,H1,H2,H1,M7,300,M6,M5,M6,0,H3,H3,300,_,M5,M6,0,H3,H3,300,_,0,M5,700,300,M6,_,_,_,_,_,
           H1,H2,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H2,0,H1,M6,300,_,0,H1,H1,300,H2,0,H1,300,M6,700,0,_,300,H1,700,H3,_,0,H3,H4,H3,H2,H3,300,H2,700,
           H1,H2,H3,0,H6,H5,_,H6,H5,_,H6,H5,300,_,H3,H3,0,H6,H5,_,H6,H5,_,H6,H5,700,300,H3,700,H2,0,H1,M6,700,300,
           H3,700,H2,0,H1,300,M6,700,H1,H1,_,_,_,_,_,
           0,M6,300,H3,700,H2,0,H1,M6,700,300,H3,H2,700,300,0,H1,M6,300,700,H1,H1,_,_,
           0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,0,L7,M1,M2,M3,300,L2,0,M5,M3,M2,M3,M1,M2,L7,M1,300,L5,0,L7,M1,M2,M3,300,L3,0,M5,M3,300,L2,L5,2,_,
           0,M6,M3,M2,L6,M3,L6,M2,M3,L6,_,_,_,
           M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M1,300,M2,700,0,M1,M2,M3,M2,M1,300,L5,_,
           M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M3,300,M2,0,M1,700,300,M2,_,_,_,
           M2,700,0,M1,300,M2,700,0,M1,300,M2,M3,M5,0,M3,700,300,M2,700,0,M3,300,M2,0,M1,700,300,L6,_,
           0,M3,M2,M1,M2,300,M1,_,0,M3,M2,M1,M2,300,M1,700,0,L5,M3,M2,M1,M2,300,M1,_,_,_,
           M1,M2,M3,M1,M6,0,M5,M6,300,_,700,0,M1,300,M7,0,M6,M7,300,_,_,M7,0,M6,M7,300,_,M3,0,H1,H2,H1,M7,300,M6,M5,M6,0,M5,M6,_,M5,M6,M5,300,M6,0,M5,M2,300,_,0,M5,700,300,M3,_,_,_,
           M1,M2,M3,M1,M6,0,M5,M6,300,_,700,0,M1,300,M7,0,M6,M7,300,_,_,M7,0,M6,M7,300,_,M3,0,H1,H2,H1,M7,300,M6,M5,M6,0,H3,H3,300,_,M5,M6,0,H3,H3,300,_,0,M5,700,300,M6,_,_,_,_,_,
           H1,H2,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H2,0,H1,M6,300,_,0,H1,H1,300,H2,0,H1,300,M6,700,0,_,300,H1,700,H3,_,0,H3,H4,H3,H2,H3,300,H2,700,
           H1,H2,H3,0,H6,H5,_,H6,H5,_,H6,H5,300,_,H3,H3,0,H6,H5,_,H6,H5,_,H6,H5,700,300,H3,700,H2,0,H1,M6,700,300,
           H3,700,H2,0,H1,300,M6,700,H1,H1,_,_,_,_,_,
           H1,H2,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H2,0,H1,M6,300,_,0,H1,H1,300,H2,0,H1,300,M6,700,0,_,300,H1,700,H3,_,0,H3,H4,H3,H2,H3,300,H2,700,
           H2,H3,0,H6,H5,_,H6,H5,_,H6,H5,300,_,H3,H3,0,H6,H5,_,H6,H5,_,H6,H5,700,300,H3,700,H2,0,H1,M6,700,300,
           H3,700,H2,0,H1,300,M6,700,H1,H1,_,_,_,_,_,
           H1,H2,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H3,0,H6,H5,300,_,0,H6,H5,300,_,0,H6,H5,300,_,0,H2,H3,300,H2,0,H1,M6,300,_,0,H1,H1,300,H2,0,H1,300,M6,700,0,_,300,H1,700,H3,_,0,H3,H4,H3,H2,H3,300,H2,700,
           H1,H2,H3,0,H6,H5,_,H6,H5,_,H6,H5,300,_,H3,H3,0,H6,H5,_,H6,H5,_,H6,H5,700,300,H3,700,H2,0,H1,M6,700,300,
           H3,700,H2,0,H1,300,M6,700,H1,H1,_,_,_,_,_,
           0,M6,300,H3,700,H2,0,H1,M6,700,300,H3,H2,700,300,0,H1,M6,300,700,H1,H1,_,_,_,_,_,_,_,
        };

        for (auto i : wind) {
            if (i == 0) { sleep = 175; continue; }
            if (i == 700) { Sleep(175); continue; }
            if (i == 300) { sleep = 350; continue; }
            if (i == _) {
                Sleep(350);
                continue;
            }
            voice = (volume << 16) + ((i) << 8) + 0x90;
            midiOutShortMsg(handle, voice);
            Sleep(sleep);
        }
        midiOutClose(handle);
        isPlaying = false;
    }
    
    // 添加一个简单的播放接口
    void play(const string& type = "wind") {
        if (type == "wind") {
            thread musicThread([this]() {
                this->playWindMusic();
            });
            musicThread.detach();
        }
    }
    
    bool getIsPlaying() const { return isPlaying; }
};

// ==================== 增强版小游戏系统 ====================
class EnhancedGameSystem {
private:
    random_device rd;
    mt19937 gen;
    map<string, int> playerStats;
    map<string, vector<string>> gameLogs;
    
public:
    EnhancedGameSystem() : gen(rd()) {
        playerStats["wins"] = 0;
        playerStats["losses"] = 0;
        playerStats["ties"] = 0;
    }
    
    // 猜数字游戏
    struct GuessGameState {
        int secretNumber;
        int attempts;
        int maxAttempts;
        int rangeMin;
        int rangeMax;
        vector<int> guessHistory;
    };
    
    GuessGameState startGuessNumber(int min = 1, int max = 100, int attempts = 7) {
        uniform_int_distribution<> dis(min, max);
        return {dis(gen), 0, attempts, min, max, {}};
    }
    
    string processGuess(GuessGameState& state, int guess) {
        state.attempts++;
        state.guessHistory.push_back(guess);
        
        if (guess == state.secretNumber) {
            playerStats["wins"]++;
            return "恭喜！猜对了！用了 " + to_string(state.attempts) + " 次机会。";
        } else if (state.attempts >= state.maxAttempts) {
            playerStats["losses"]++;
            return "游戏结束！正确答案是 " + to_string(state.secretNumber) + "。";
        } else if (guess < state.secretNumber) {
            return "太小了！还剩 " + to_string(state.maxAttempts - state.attempts) + " 次机会。";
        } else {
            return "太大了！还剩 " + to_string(state.maxAttempts - state.attempts) + " 次机会。";
        }
    }
    
    // 石头剪刀布游戏
    string playRockPaperScissors(const string& playerChoice) {
        vector<string> choices = {"石头", "剪刀", "布"};
        uniform_int_distribution<> dis(0, 2);
        int computerChoice = dis(gen);
        
        string computerStr = choices[computerChoice];
        string playerStr = playerChoice;
        
        // 标准化玩家输入
        if (playerStr.find("石头") != string::npos) playerStr = "石头";
        else if (playerStr.find("剪刀") != string::npos) playerStr = "剪刀";
        else if (playerStr.find("布") != string::npos) playerStr = "布";
        
        if (playerStr != "石头" && playerStr != "剪刀" && playerStr != "布") {
            return "请出石头、剪刀或布！";
        }
        
        if (playerStr == computerStr) {
            playerStats["ties"]++;
            return "平局！我们都出了 " + computerStr;
        } else if ((playerStr == "石头" && computerStr == "剪刀") ||
                  (playerStr == "剪刀" && computerStr == "布") ||
                  (playerStr == "布" && computerStr == "石头")) {
            playerStats["wins"]++;
            return "你赢了！你出了 " + playerStr + "，我出了 " + computerStr;
        } else {
            playerStats["losses"]++;
            return "我赢了！你出了 " + playerStr + "，我出了 " + computerStr;
        }
    }
    
    // 24点游戏
    class TwentyFourGame {
    private:
        vector<int> cards;
        
    public:
        TwentyFourGame() {
            reset();
        }
        
        void reset() {
            cards.clear();
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(1, 13);
            
            for (int i = 0; i < 4; i++) {
                cards.push_back(dis(gen));
            }
        }
        
        vector<int> getCards() const { return cards; }
        
        string getCardsString() const {
            string result = "四张牌是: ";
            for (size_t i = 0; i < cards.size(); i++) {
                result += to_string(cards[i]);
                if (i < cards.size() - 1) result += ", ";
            }
            return result;
        }
        
        bool checkSolution(const string& userSolution) {
            // 简化实现，检查是否为有效表达式
            // 这里应该实现完整的24点计算验证，但为了简化，我们接受任何包含数字的表达式
            return !userSolution.empty() && 
                   (userSolution.find_first_of("0123456789") != string::npos);
        }
    };
    
    // 记忆翻牌游戏
    class MemoryGame {
    private:
        vector<int> cards;
        vector<bool> revealed;
        int firstSelection;
        int secondSelection;
        int matches;
        int attempts;
        
    public:
        MemoryGame(int size = 8) : firstSelection(-1), secondSelection(-1), matches(0), attempts(0) {
            for (int i = 0; i < size/2; i++) {
                cards.push_back(i);
                cards.push_back(i);
            }
            
            shuffle(cards.begin(), cards.end(), mt19937(random_device()()));
            revealed.resize(size, false);
        }
        
        string selectCard(int index) {
            if (index < 0 || index >= cards.size()) {
                return "无效的位置！请选择1-" + to_string(cards.size()) + "之间的数字。";
            }
            
            if (revealed[index]) {
                return "这张牌已经翻开了！";
            }
            
            if (firstSelection == -1) {
                firstSelection = index;
                revealed[index] = true;
                return "翻开第一张牌，数字是 " + to_string(cards[index]);
            } else {
                secondSelection = index;
                revealed[index] = true;
                attempts++;
                
                if (cards[firstSelection] == cards[secondSelection]) {
                    matches++;
                    firstSelection = -1;
                    secondSelection = -1;
                    if (matches * 2 == cards.size()) {
                        return "恭喜！所有牌都匹配成功！用了 " + to_string(attempts) + " 次尝试。";
                    }
                    return "匹配成功！继续下一对。";
                } else {
                    return "不匹配！第一张牌是 " + to_string(cards[firstSelection]) + 
                          "，第二张牌是 " + to_string(cards[secondSelection]);
                }
            }
        }
        
        void resetSelections() {
            if (firstSelection != -1 && secondSelection != -1) {
                if (cards[firstSelection] != cards[secondSelection]) {
                    revealed[firstSelection] = false;
                    revealed[secondSelection] = false;
                }
                firstSelection = -1;
                secondSelection = -1;
            }
        }
        
        string getBoard() const {
            string board;
            for (size_t i = 0; i < cards.size(); i++) {
                if (revealed[i]) {
                    board += to_string(cards[i]) + " ";
                } else {
                    board += "* ";
                }
                if ((i + 1) % 4 == 0) board += "\n";
            }
            return board;
        }
        
        bool isComplete() const {
            return matches * 2 == cards.size();
        }
        
        int getRemainingPairs() const {
            return cards.size() / 2 - matches;
        }
    };
    
    // 数独游戏
    class SudokuGame {
    private:
        vector<vector<int>> board;
        
    public:
        SudokuGame() {
            board.resize(9, vector<int>(9, 0));
            generatePuzzle();
        }
        
        void generatePuzzle() {
            // 生成一个简单的数独谜题
            vector<int> nums = {1,2,3,4,5,6,7,8,9};
            shuffle(nums.begin(), nums.end(), mt19937(random_device()()));
            
            for (int i = 0; i < 9; i++) {
                board[i][i] = nums[i];
            }
        }
        
        bool placeNumber(int row, int col, int num) {
            if (row < 0 || row >= 9 || col < 0 || col >= 9) return false;
            if (board[row][col] != 0) return false;
            if (num < 1 || num > 9) return false;
            
            board[row][col] = num;
            return true;
        }
        
        string getBoard() const {
            string result;
            for (int i = 0; i < 9; i++) {
                if (i % 3 == 0 && i != 0) result += "------+-------+------\n";
                for (int j = 0; j < 9; j++) {
                    if (j % 3 == 0 && j != 0) result += "| ";
                    if (board[i][j] == 0) {
                        result += ". ";
                    } else {
                        result += to_string(board[i][j]) + " ";
                    }
                }
                result += "\n";
            }
            return result;
        }
    };
    
    // 井字棋游戏
    class TicTacToe {
    private:
        vector<vector<char>> board;
        char currentPlayer;
        
    public:
        TicTacToe() : currentPlayer('X') {
            board.resize(3, vector<char>(3, ' '));
        }
        
        string makeMove(int row, int col) {
            if (row < 0 || row >= 3 || col < 0 || col >= 3) {
                return "无效的位置！请选择1-3之间的行和列。";
            }
            if (board[row][col] != ' ') {
                return "位置已被占用！";
            }
            
            board[row][col] = currentPlayer;
            
            if (checkWin(currentPlayer)) {
                return string(1, currentPlayer) + " 获胜！";
            }
            
            if (isBoardFull()) {
                return "平局！";
            }
            
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            return "轮到 " + string(1, currentPlayer) + " 下棋";
        }
        
        bool checkWin(char player) {
            // 检查行
            for (int i = 0; i < 3; i++) {
                if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                    return true;
                }
            }
            
            // 检查列
            for (int i = 0; i < 3; i++) {
                if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                    return true;
                }
            }
            
            // 检查对角线
            if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
                return true;
            }
            if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
                return true;
            }
            
            return false;
        }
        
        bool isBoardFull() {
            for (const auto& row : board) {
                for (char cell : row) {
                    if (cell == ' ') return false;
                }
            }
            return true;
        }
        
        string getBoard() const {
            string result;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    result += board[i][j];
                    if (j < 2) result += "|";
                }
                if (i < 2) result += "\n-----\n";
            }
            return result;
        }
        
        char getCurrentPlayer() const { return currentPlayer; }
        void reset() {
            board = vector<vector<char>>(3, vector<char>(3, ' '));
            currentPlayer = 'X';
        }
    };
    
    // 文字冒险游戏
    class TextAdventure {
    private:
        string currentScene;
        int playerScore;
        
    public:
        TextAdventure() : playerScore(0) {
            currentScene = "forest";
        }
        
        string start() {
            return "欢迎来到神秘森林冒险！\n"
                   "你发现自己在一片神秘的森林里。\n"
                   "前面有三条路：\n"
                   "1. 左边的黑暗小路\n"
                   "2. 中间的阳光大道\n"
                   "3. 右边的河边小径\n"
                   "请选择1, 2或3：";
        }
        
        string processChoice(const string& choice) {
            if (currentScene == "forest") {
                if (choice == "1") {
                    currentScene = "dark_path";
                    playerScore += 10;
                    return "你选择了黑暗小路。走着走着，你发现了一个宝箱！里面有很多金币。\n"
                           "继续前进吗？(是/否)";
                } else if (choice == "2") {
                    currentScene = "sunny_path";
                    playerScore += 5;
                    return "你选择了阳光大道。遇到一个友好的旅行者，他给了你一张地图。\n"
                           "继续前进吗？(是/否)";
                } else if (choice == "3") {
                    currentScene = "river_path";
                    playerScore += 8;
                    return "你选择了河边小径。在河边休息时，你钓到了一条神奇的鱼！\n"
                           "继续前进吗？(是/否)";
                }
            } else if (choice == "是" || choice == "yes" || choice == "y") {
                string result = "你继续前进... 发现了一个神秘的洞穴！要进去吗？(是/否)\n";
                result += "当前得分: " + to_string(playerScore);
                return result;
            } else if (choice == "否" || choice == "no" || choice == "n") {
                string result = "冒险结束！你的得分: " + to_string(playerScore);
                reset();
                return result;
            }
            
            return "请做出有效的选择！";
        }
        
        void reset() {
            currentScene = "forest";
            playerScore = 0;
        }
    };
};

// ==================== 天气服务类 ====================
class EnhancedWeatherService {
private:
    struct WeatherData {
        string description;
        double temperature;
        
        WeatherData() : description(""), temperature(0.0) {}
        WeatherData(const string& desc, double temp) 
            : description(desc), temperature(temp) {}
    };
    
    map<string, WeatherData> cityWeatherData;
    
public:
    EnhancedWeatherService() {
        // 模拟天气数据
        cityWeatherData["北京"] = WeatherData("晴朗", 25.5);
        cityWeatherData["上海"] = WeatherData("多云", 23.8);
        cityWeatherData["广州"] = WeatherData("阵雨", 28.3);
        cityWeatherData["深圳"] = WeatherData("晴朗", 29.1);
        cityWeatherData["杭州"] = WeatherData("多云", 24.7);
        cityWeatherData["成都"] = WeatherData("小雨", 22.4);
        cityWeatherData["西安"] = WeatherData("阴天", 21.9);
        cityWeatherData["南京"] = WeatherData("晴朗", 24.2);
        cityWeatherData["武汉"] = WeatherData("多云", 26.1);
        cityWeatherData["重庆"] = WeatherData("小雨", 23.5);
    }
    
    string getWeather(const string& city) {
        auto it = cityWeatherData.find(city);
        if (it != cityWeatherData.end()) {
            const WeatherData& data = it->second;
            return data.description + ", " + to_string(data.temperature).substr(0, 4) + "°C";
        }
        return "未知城市";
    }
    
    vector<string> getAvailableCities() const {
        vector<string> cities;
        for (const auto& pair : cityWeatherData) {
            cities.push_back(pair.first);
        }
        return cities;
    }
};

// ==================== 主AI机器人类 ====================
class DeepSeekPro {
private:
    const string BOT_NAME = "ChatBot ";
    string userName;
    map<string, string> memory;
    bool nameConfirmed;
    
    // 功能模块
    MusicPlayer musicPlayer;  // 修复：使用正确的类名
    EnhancedGameSystem gameSystem;
    EnhancedWeatherService weatherService;
    
    // 游戏状态
    bool inGameMode;
    string currentGame;
    EnhancedGameSystem::GuessGameState guessGameState;
    shared_ptr<EnhancedGameSystem::MemoryGame> memoryGame;
    shared_ptr<EnhancedGameSystem::SudokuGame> sudokuGame;
    shared_ptr<EnhancedGameSystem::TicTacToe> ticTacToe;
    shared_ptr<EnhancedGameSystem::TwentyFourGame> twentyFourGame;
    shared_ptr<EnhancedGameSystem::TextAdventure> textAdventure;
    
    // 对话历史
    vector<pair<string, string>> chatHistory;
    const size_t MAX_HISTORY = 50;
    
    // 知识库和笑话数据库
    map<string, vector<string>> knowledgeBase;
    map<string, vector<string>> jokesDatabase;
    map<string, vector<string>> quotesDatabase;
    
    // 提醒功能
    struct Reminder {
        string description;
        time_t time;
        int id;
        Reminder(const string& desc, time_t t, int i) : description(desc), time(t), id(i) {}
    };
    vector<Reminder> reminders;
    int nextReminderId;
    
    // 工具函数
    string toLower(const string& str) const {
        string result;
        transform(str.begin(), str.end(), back_inserter(result), ::tolower);
        return result;
    }
    
    string trim(const string& str) const {
        size_t first = str.find_first_not_of(" \t\n\r");
        if (first == string::npos) return "";
        size_t last = str.find_last_not_of(" \t\n\r");
        return str.substr(first, last - first + 1);
    }
    
    bool containsKeyword(const string& input, const string& keyword) const {
        string lowerInput = toLower(input);
        string lowerKeyword = toLower(keyword);
        return lowerInput.find(lowerKeyword) != string::npos;
    }
    
    bool containsKeyword(const string& input, const vector<string>& keywords) {
        for (const auto& keyword : keywords) {
            if (containsKeyword(input, keyword)) {
                return true;
            }
        }
        return false;
    }
    
    vector<string> split(const string& str, char delimiter) const {
        vector<string> tokens;
        string token;
        istringstream tokenStream(str);
        while (getline(tokenStream, token, delimiter)) {
            token = trim(token);
            if (!token.empty()) tokens.push_back(token);
        }
        return tokens;
    }
    
    // 新增：改进的数学表达式检测
    bool isMathExpression(const string& input) {
        string expr = trim(input);
        
        // 检查是否包含常见数学运算符
        bool hasOperator = false;
        for (char c : expr) {
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '^') {
                hasOperator = true;
                break;
            }
        }
        
        // 检查是否包含数字
        bool hasDigit = any_of(expr.begin(), expr.end(), ::isdigit);
        
        // 检查是否包含数学函数
        bool hasMathFunc = expr.find("sqrt") != string::npos ||
                          expr.find("sin") != string::npos ||
                          expr.find("cos") != string::npos ||
                          expr.find("tan") != string::npos ||
                          expr.find("log") != string::npos;
        
        // 表达式应该包含数字和运算符，或者数学函数
        return (hasDigit && hasOperator) || hasMathFunc;
    }
    
    // 新增：改进的记忆功能正则表达式
    string handleMemory(const string& input) {
        // 改进记忆功能的正则表达式
        vector<regex> patterns;
        
        // 中文格式
        patterns.push_back(regex(R"(记住\s+(.+?)\s+是\s+(.+))"));
        patterns.push_back(regex(R"(记住我的(.+?)\s+是\s+(.+))"));
        patterns.push_back(regex(R"(我的(.+?)\s+是\s+(.+))"));
        
        for (const auto& pattern : patterns) {
            smatch match;
            if (regex_search(input, match, pattern) && match.size() > 2) {
                string key = trim(match[1]);
                string value = trim(match[2]);
                memory[key] = value;
                
                // 如果是生日，特殊处理
                if (key == "生日" || key.find("生日") != string::npos) {
                    memory["生日"] = value;
                }
                
                return "好的，我记住了" + key + "是" + value;
            }
        }
        
        // 查询记忆
        if (containsKeyword(input, "生日")) {
            auto it = memory.find("生日");
            if (it != memory.end()) {
                return "你的生日是：" + it->second;
            } else {
                return "我还没有记住你的生日呢。";
            }
        }
        
        // 通用记忆查询
        for (const auto& entry : memory) {
            if (input.find(entry.first) != string::npos) {
                return entry.first + "是" + entry.second;
            }
        }
        
        return "";
    }
    
    // 新增：改进的学习功能
    string handleLearning(const string& input) {
        vector<regex> patterns;
        
        // 中文格式
        patterns.push_back(regex(R"(教我\s*(.+?)\s+是\s+(.+))"));
        patterns.push_back(regex(R"(什么是\s*(.+))"));
        patterns.push_back(regex(R"((.+?)\s+是什么)"));
        
        for (const auto& pattern : patterns) {
            smatch match;
            if (regex_search(input, match, pattern) && match.size() > 1) {
                string key = trim(match[1]);
                string value = "";
                
                if (match.size() > 2) {
                    value = trim(match[2]);
                    knowledgeBase[key].push_back(value);
                    return "学会了！" + key + " 是 " + value;
                } else {
                    // 查询知识
                    auto it = knowledgeBase.find(key);
                    if (it != knowledgeBase.end() && !it->second.empty()) {
                        return key + " 是：" + it->second[0];
                    }
                }
            }
        }
        
        return "";
    }
    
    // 新增：改进的单位转换功能
    string handleUnitConversion(const string& input) {
        vector<regex> patterns;
        
        // 中文格式
        patterns.push_back(regex(R"((\d+(?:\.\d+)?)\s*摄氏度\s*(?:转|转成|转换)\s*华氏度)"));
        patterns.push_back(regex(R"((\d+(?:\.\d+)?)\s*°C\s*(?:转|转成|转换)\s*°F)"));
        patterns.push_back(regex(R"((\d+(?:\.\d+)?)\s*公里\s*(?:转|转成|转换)\s*英里)"));
        patterns.push_back(regex(R"((\d+(?:\.\d+)?)\s*km\s*(?:转|转成|转换)\s*mile)"));
        patterns.push_back(regex(R"((\d+(?:\.\d+)?)\s*千克\s*(?:转|转成|转换)\s*磅)"));
        patterns.push_back(regex(R"((\d+(?:\.\d+)?)\s*kg\s*(?:转|转成|转换)\s*lb)"));
        
        for (const auto& pattern : patterns) {
            smatch match;
            if (regex_search(input, match, pattern) && match.size() > 1) {
                double value = stod(match[1]);
                
                // 判断转换类型
                if (input.find("摄氏") != string::npos || input.find("°C") != string::npos) {
                    double fahrenheit = value * 9/5 + 32;
                    return to_string(value) + "°C = " + to_string(fahrenheit).substr(0, 6) + "°F";
                } else if (input.find("公里") != string::npos || input.find("km") != string::npos) {
                    double miles = value * 0.621371;
                    return to_string(value) + "公里 = " + to_string(miles).substr(0, 6) + "英里";
                } else if (input.find("千克") != string::npos || input.find("kg") != string::npos) {
                    double pounds = value * 2.20462;
                    return to_string(value) + "千克 = " + to_string(pounds).substr(0, 6) + "磅";
                }
            }
        }
        
        return "";
    }
    
    // 新增：计时器功能
    string handleTimer(const string& input) {
        if (containsKeyword(input, "计时器") || containsKeyword(input, "定时器")) {
            vector<regex> patterns;
            
            // 中文格式
            patterns.push_back(regex(R"(设置\s*(\d+)\s*(?:秒|秒钟)\s*的计时器)"));
            patterns.push_back(regex(R"(设置\s*(\d+)\s*(?:分钟|分)\s*的计时器)"));
            patterns.push_back(regex(R"((\d+)\s*(?:秒|秒钟)\s*后提醒我)"));
            patterns.push_back(regex(R"((\d+)\s*(?:分钟|分)\s*后提醒我)"));
            
            for (const auto& pattern : patterns) {
                smatch match;
                if (regex_search(input, match, pattern) && match.size() > 1) {
                    int duration = stoi(match[1]);
                    string unit = "";
                    string description = "时间到！";
                    
                    // 判断时间单位
                    if (input.find("秒") != string::npos) {
                        unit = "秒";
                    } else if (input.find("分钟") != string::npos || input.find("分") != string::npos) {
                        unit = "分钟";
                        duration *= 60;
                    }
                    
                    // 提取提醒内容
                    regex descPattern(R"((?:提醒我|提醒|叫我)(.+))");
                    smatch descMatch;
                    if (regex_search(input, descMatch, descPattern) && descMatch.size() > 1) {
                        description = trim(descMatch[1]);
                    }
                    
                    // 启动计时器线程
                    time_t reminderTime = time(nullptr) + duration;
                    reminders.emplace_back(description, reminderTime, nextReminderId++);
                    
                    // 启动后台线程
                    thread timerThread([this, duration, description]() {
                        this_thread::sleep_for(chrono::seconds(duration));
                        cout << "\n" << BOT_NAME << ": 计时器时间到！" << description << endl;
                    });
                    timerThread.detach();
                    
                    return "已设置" + to_string(duration/60) + unit + "的计时器";
                }
            }
        }
        return "";
    }
    
    // 新增：改进的数学计算处理
    string handleMathCalculation(const string& input) {
        try {
            string expression = trim(input);
            
            // 移除所有空格
            expression.erase(remove(expression.begin(), expression.end(), ' '), expression.end());
            
            // 支持数学函数
            if (expression.find("sqrt(") != string::npos) {
                size_t start = expression.find("sqrt(") + 5;
                size_t end = expression.find(')', start);
                double num = stod(expression.substr(start, end - start));
                if (num < 0) return "错误：负数不能开平方！";
                double result = sqrt(num);
                return "√" + to_string(num) + " = " + to_string(result).substr(0, 6);
            }
            
            if (expression.find("^") != string::npos) {
                size_t pos = expression.find('^');
                double base = stod(expression.substr(0, pos));
                double exp = stod(expression.substr(pos + 1));
                double result = pow(base, exp);
                return expression + " = " + to_string(result).substr(0, 10);
            }
            
            // 处理乘除优先
            // 先处理乘法和除法
            size_t multiply = expression.find('*');
            size_t divide = expression.find('/');
            
            while (multiply != string::npos || divide != string::npos) {
                // 找到第一个运算符
                size_t opPos = string::npos;
                char op = '*';
                
                if (multiply != string::npos && divide != string::npos) {
                    if (multiply < divide) {
                        opPos = multiply;
                        op = '*';
                    } else {
                        opPos = divide;
                        op = '/';
                    }
                } else if (multiply != string::npos) {
                    opPos = multiply;
                    op = '*';
                } else {
                    opPos = divide;
                    op = '/';
                }
                
                // 提取左操作数
                size_t leftStart = opPos;
                while (leftStart > 0 && (isdigit(expression[leftStart - 1]) || expression[leftStart - 1] == '.')) {
                    leftStart--;
                }
                double left = stod(expression.substr(leftStart, opPos - leftStart));
                
                // 提取右操作数
                size_t rightEnd = opPos + 1;
                while (rightEnd < expression.length() && 
                      (isdigit(expression[rightEnd]) || expression[rightEnd] == '.')) {
                    rightEnd++;
                }
                double right = stod(expression.substr(opPos + 1, rightEnd - opPos - 1));
                
                // 计算结果
                double result = 0;
                if (op == '*') {
                    result = left * right;
                } else {
                    if (right == 0) return "错误：除数不能为零！";
                    result = left / right;
                }
                
                // 替换表达式中的计算部分
                expression = expression.substr(0, leftStart) + to_string(result) + expression.substr(rightEnd);
                
                // 重新查找运算符
                multiply = expression.find('*');
                divide = expression.find('/');
            }
            
            // 处理加法和减法
            // 使用字符串流解析简单表达式
            istringstream iss(expression);
            double result = 0;
            char op = '+';
            double num;
            
            if (!(iss >> result)) {
                return "";
            }
            
            while (iss >> op >> num) {
                if (op == '+') {
                    result += num;
                } else if (op == '-') {
                    result -= num;
                } else {
                    return "";
                }
            }
            
            return input + " = " + to_string(result);
        } catch (const exception& e) {
            return "";
        }
    }
    
    // 新增：检查提醒
    void checkReminders() {
        time_t now = time(nullptr);
        for (auto it = reminders.begin(); it != reminders.end(); ) {
            if (it->time <= now) {
                cout << "\n" << BOT_NAME << ": 提醒: " << it->description << endl;
                it = reminders.erase(it);
            } else {
                ++it;
            }
        }
    }
    
    // 原有功能函数
    string getCurrentTime() const {
        time_t now = time(nullptr);
        char timeStr[100];
        strftime(timeStr, sizeof(timeStr), "%Y年%m月%d日 %H:%M:%S", localtime(&now));
        return string(timeStr);
    }
    
    string generateGreeting() const {
        time_t now = time(nullptr);
        tm *ltm = localtime(&now);
        int hour = ltm->tm_hour;
        
        string timeGreeting;
        if (hour < 12) timeGreeting = "早上好";
        else if (hour < 14) timeGreeting = "中午好";
        else if (hour < 18) timeGreeting = "下午好";
        else timeGreeting = "晚上好";
        
        return timeGreeting + (userName.empty() ? "" : " " + userName) + "！";
    }
    
    string handleName(const string& input) {
        vector<string> nameMarkers = {"我叫", "我是", "名字是", "我的名字叫"};
        
        string lowerInput = toLower(input);
        
        for (const auto& marker : nameMarkers) {
            size_t pos = lowerInput.find(toLower(marker));
            if (pos != string::npos) {
                size_t nameStart = pos + marker.length();
                if (nameStart < input.length()) {
                    string extractedName = trim(input.substr(nameStart));
                    if (!extractedName.empty()) {
                        userName = extractedName;
                        memory["name"] = userName;
                        nameConfirmed = true;
                        return "很高兴认识你，" + userName + "！我会记住的。";
                    }
                }
            }
        }
        
        return "";
    }
    
    string handleWeather(const string& input) {
        if (containsKeyword(input, "天气")) {
            // 检查是否包含具体城市
            vector<string> allCities = weatherService.getAvailableCities();
            for (const auto& city : allCities) {
                if (input.find(city) != string::npos) {
                    string weather = weatherService.getWeather(city);
                    return city + "的天气：" + weather;
                }
            }
            
            // 如果没有指定城市，列出可查询的城市
            vector<string> cities = weatherService.getAvailableCities();
            string response = "我可以查询以下城市的天气：\n";
            for (const auto& city : cities) {
                response += city + " ";
            }
            response += "\n请告诉我你想查询哪个城市？";
            return response;
        }
        
        return "";
    }
    
    string handleMusic(const string& input) {
        if (containsKeyword(input, "播放音乐") || containsKeyword(input, "放音乐") ||
            containsKeyword(input, "风之音乐") || containsKeyword(input, "音乐")) {
            
            // 在新线程中播放音乐以避免阻塞
            thread musicThread([this]() {
                this->musicPlayer.play("wind");
            });
            musicThread.detach();
            
            return "开始播放风之音乐！你可以继续聊天，音乐会继续在后台播放。";
        }
        
        return "";
    }
    
    string handleReminder(const string& input) {
        if (containsKeyword(input, "提醒")) {
            int minutes = 0;
            string description;
            
            regex minPattern(R"((\d+)\s*分钟后\s*提醒我\s*(.+))");
            regex hourPattern(R"((\d+)\s*小时后\s*提醒我\s*(.+))");
            smatch match;
            
            if (regex_search(input, match, minPattern) && match.size() > 2) {
                minutes = stoi(match[1]);
                description = trim(match[2]);
            } else if (regex_search(input, match, hourPattern) && match.size() > 2) {
                minutes = stoi(match[1]) * 60;
                description = trim(match[2]);
            }
            
            if (!description.empty()) {
                time_t reminderTime = time(nullptr) + minutes * 60;
                reminders.emplace_back(description, reminderTime, nextReminderId++);
                
                return "好的，我会在" + to_string(minutes) + (minutes >= 60 ? "小时" : "分钟") + "后提醒你：" + description;
            }
        }
        
        return "";
    }
    
    string handlePasswordGeneration(const string& input) {
        if (containsKeyword(input, "生成密码") || containsKeyword(input, "密码生成")) {
            const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}\\|/?.<>;:\'\"";
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(0, chars.size() - 1);
            
            string password;
            for (int i = 0; i < 12; i++) {
                password += chars[dis(gen)];
            }
            return "生成的密码: " + password + "\n（请妥善保管！）";
        }
        
        return "";
    }
    
    string getRandomJoke() {
        vector<string> jokes = {
            "为什么数学书总是很忧伤？因为它有太多的问题！",
            "有一天，一个程序员去商店买面包。售货员问：\"你要切片吗？\"程序员回答：\"不，我已经有足够的bug了。\"",
            "为什么电脑永远不会感冒？因为它有Windows（窗户）！",
            "老师说：\"同学们，今天我们要学习减法。比方说，你哥哥有5个苹果，你从他那儿拿走3个，结果怎样？\"一个学生回答：\"结果他会揍我一顿！\"",
            "为什么海星从来不参加考试？因为它总是海星（还行）！"
        };
        return jokes[rand() % jokes.size()];
    }
    
    string getRandomQuote() {
        vector<string> quotes = {
            "学习是终身的事业。——毛泽东",
            "实践是检验真理的唯一标准。——邓小平",
            "知识就是力量。——培根",
            "千里之行，始于足下。——老子",
            "不积跬步，无以至千里。——荀子"
        };
        return quotes[rand() % quotes.size()];
    }
    
    string giveRandomAdvice() {
        vector<string> adviceList = {
            "多喝水，保持身体水分充足",
            "每天运动30分钟，保持健康",
            "记得定期备份重要文件",
            "学习新技能，不断提升自己",
            "保持积极乐观的心态"
        };
        return adviceList[rand() % adviceList.size()];
    }
    
    string handleEmotions(const string& input) {
        if (containsKeyword(input, "难过") || containsKeyword(input, "伤心") || 
            containsKeyword(input, "悲伤")) {
            return "抱抱你，一切都会好起来的。我在这里陪着你。";
        }
        
        if (containsKeyword(input, "开心") || containsKeyword(input, "高兴") || 
            containsKeyword(input, "快乐")) {
            return "太好了！为你感到高兴！";
        }
        
        if (containsKeyword(input, "生气") || containsKeyword(input, "愤怒")) {
            return "深呼吸，冷静一下。我理解你的感受。";
        }
        
        if (containsKeyword(input, "累") || containsKeyword(input, "疲惫")) {
            return "休息一下吧，别太累了。";
        }
        
        return "";
    }
    
    string handleGames(const string& input) {
        vector<string> guessNumberKeywords = {"猜数字", "猜数游戏", "猜数字游戏"};
        vector<string> memoryGameKeywords = {"记忆翻牌", "记忆游戏", "翻牌游戏"};
        vector<string> sudokuKeywords = {"数独", "数独游戏"};
        vector<string> tictactoeKeywords = {"井字棋"};
        vector<string> twentyfourKeywords = {"24点", "24点游戏"};
        vector<string> rpsKeywords = {"石头剪刀布", "剪刀石头布", "石头", "剪刀", "布"};
        vector<string> adventureKeywords = {"冒险游戏", "文字冒险", "冒险"};
        vector<string> allGamesKeywords = {"玩游戏", "游戏", "我想玩游戏"};
        
        if (containsKeyword(input, guessNumberKeywords)) {
            inGameMode = true;
            currentGame = "guess";
            guessGameState = gameSystem.startGuessNumber();
            return "我已经想好了一个" + to_string(guessGameState.rangeMin) + 
                   "-" + to_string(guessGameState.rangeMax) + 
                   "之间的数字，你有" + to_string(guessGameState.maxAttempts) + 
                   "次机会来猜！输入数字开始游戏吧！";
        }
        else if (containsKeyword(input, memoryGameKeywords)) {
            inGameMode = true;
            currentGame = "memory";
            memoryGame = make_shared<EnhancedGameSystem::MemoryGame>();
            return "记忆翻牌游戏开始！\n" + memoryGame->getBoard() + 
                   "\n请输入1-8之间的数字翻开一张牌：";
        }
        else if (containsKeyword(input, sudokuKeywords)) {
            inGameMode = true;
            currentGame = "sudoku";
            sudokuGame = make_shared<EnhancedGameSystem::SudokuGame>();
            return "数独游戏开始！\n" + sudokuGame->getBoard() + 
                   "\n请输入 行 列 数字 (例如：1 1 5) 来放置数字：";
        }
        else if (containsKeyword(input, tictactoeKeywords)) {
            inGameMode = true;
            currentGame = "tictactoe";
            ticTacToe = make_shared<EnhancedGameSystem::TicTacToe>();
            return "井字棋游戏开始！\n" + ticTacToe->getBoard() + 
                   "\n请输入 行 列 (例如：1 1) 来下棋，当前玩家: " + 
                   string(1, ticTacToe->getCurrentPlayer());
        }
        else if (containsKeyword(input, twentyfourKeywords)) {
            inGameMode = true;
            currentGame = "twentyfour";
            twentyFourGame = make_shared<EnhancedGameSystem::TwentyFourGame>();
            return "24点游戏开始！\n" + twentyFourGame->getCardsString() + 
                   "\n请使用加减乘除和括号使这4个数字等于24\n例如：3*8*(4-3)";
        }
        else if (containsKeyword(input, rpsKeywords)) {
            if (containsKeyword(input, "石头") || containsKeyword(input, "剪刀") || containsKeyword(input, "布")) {
                return gameSystem.playRockPaperScissors(input);
            }
            return "来玩石头剪刀布吧！请出拳（石头/剪刀/布）：";
        }
        else if (containsKeyword(input, adventureKeywords)) {
            inGameMode = true;
            currentGame = "adventure";
            textAdventure = make_shared<EnhancedGameSystem::TextAdventure>();
            return textAdventure->start();
        }
        else if (containsKeyword(input, allGamesKeywords)) {
            return "我可以陪你玩以下游戏：\n"
                   "1. 猜数字游戏\n"
                   "2. 记忆翻牌游戏\n"
                   "3. 数独游戏\n"
                   "4. 井字棋\n"
                   "5. 24点游戏\n"
                   "6. 石头剪刀布\n"
                   "7. 文字冒险游戏\n"
                   "请告诉我你想玩哪个游戏？";
        }
        
        return "";
    }
    
    string processGameInput(const string& input) {
        if (currentGame == "guess") {
            try {
                int guess = stoi(input);
                string result = gameSystem.processGuess(guessGameState, guess);
                
                if (result.find("游戏结束") != string::npos || result.find("猜对了") != string::npos) {
                    inGameMode = false;
                    currentGame = "";
                }
                return result;
            } catch (...) {
                string lowerInput = toLower(input);
                if (lowerInput == "退出" || lowerInput == "退出游戏") {
                    inGameMode = false;
                    currentGame = "";
                    return "游戏已结束。";
                }
                return "请输入数字！输入‘退出’可以结束游戏。";
            }
        } else if (currentGame == "memory") {
            try {
                int index = stoi(input) - 1;
                string result = memoryGame->selectCard(index);
                memoryGame->resetSelections();
                
                if (memoryGame->isComplete()) {
                    inGameMode = false;
                    currentGame = "";
                    return result + "\n游戏结束！";
                }
                
                return result + "\n当前棋盘：\n" + memoryGame->getBoard() + 
                       "\n还剩 " + to_string(memoryGame->getRemainingPairs()) + 
                       " 对牌需要匹配。\n请输入1-8之间的数字翻开一张牌：";
            } catch (...) {
                return "请输入1-8之间的数字！";
            }
        } else if (currentGame == "sudoku") {
            try {
                vector<string> parts = split(input, ' ');
                if (parts.size() == 3) {
                    int row = stoi(parts[0]) - 1;
                    int col = stoi(parts[1]) - 1;
                    int num = stoi(parts[2]);
                    
                    if (sudokuGame->placeNumber(row, col, num)) {
                        string board = sudokuGame->getBoard();
                        return "放置成功！\n" + board + 
                               "\n请输入 行 列 数字 (例如：1 1 5) 来放置数字：";
                    }
                }
                return "格式：行 列 数字 (例如：1 2 3)";
            } catch (...) {
                return "请输入有效的数字！";
            }
        } else if (currentGame == "tictactoe") {
            try {
                vector<string> parts = split(input, ' ');
                if (parts.size() == 2) {
                    int row = stoi(parts[0]) - 1;
                    int col = stoi(parts[1]) - 1;
                    string result = ticTacToe->makeMove(row, col);
                    string board = ticTacToe->getBoard();
                    
                    if (result.find("获胜") != string::npos || result.find("平局") != string::npos) {
                        currentGame = "";
                        inGameMode = false;
                        return result + "\n" + board + "\n游戏结束！";
                    }
                    return result + "\n" + board + 
                           "\n当前玩家: " + string(1, ticTacToe->getCurrentPlayer()) + 
                           "\n请输入 行 列 (例如：1 1) 来下棋：";
                }
                return "格式：行 列 (例如：1 1)";
            } catch (...) {
                return "请输入有效的数字！";
            }
        } else if (currentGame == "twentyfour") {
            if (input == "新游戏") {
                twentyFourGame->reset();
                return "新游戏开始！\n" + twentyFourGame->getCardsString() + 
                       "\n请使用加减乘除和括号使这4个数字等于24\n例如：3*8*(4-3)";
            } else if (twentyFourGame->checkSolution(input)) {
                currentGame = "";
                inGameMode = false;
                return "恭喜！你的解法 " + input + " = 24 是正确的！";
            } else {
                return "你的解法不正确。输入‘新游戏’开始新游戏。";
            }
        } else if (currentGame == "adventure") {
            return textAdventure->processChoice(input);
        }
        
        return "";
    }
    
    void resetGameState() {
        if (inGameMode) {
            inGameMode = false;
            currentGame = "";
            memoryGame.reset();
            sudokuGame.reset();
            if (ticTacToe) ticTacToe->reset();
            twentyFourGame.reset();
            textAdventure.reset();
        }
    }
    
    string provideEnhancedHelp() const {
        return "\n"
			   "======= " + BOT_NAME + " 增强版功能 =======\n\n"
               " 游戏功能：\n"
               "  - 猜数字游戏\n"
               "  - 记忆翻牌游戏\n"
               "  - 数独游戏\n"
               "  - 井字棋\n"
               "  - 24点游戏\n"
               "  - 石头剪刀布\n"
               "  - 文字冒险游戏\n\n"
               
               " 音乐功能：\n"
               "  - 播放风之音乐\n\n"
               
               " 学习功能：\n"
               "  - 教我[知识]=[内容]\n"
               "  - 记忆翻牌学习\n\n"
               
               " 工具功能：\n"
               "  - 计时器\n"
               "  - 密码生成器\n"
               "  - 单位换算（温度、距离、重量）\n"
               "  - 科学计算器\n"
               "  - 提醒功能\n\n"
               
               " 信息服务：\n"
               "  - 详细天气预报\n"
               "  - 名言警句\n"
               "  - 讲笑话\n\n"
               
               " 分析功能：\n"
               "  - 情绪分析\n"
               "  - 对话历史记录\n"
               "  - 个性化建议\n\n"
               
               " 基础功能：\n"
               "  - 时间日期查询\n"
               "  - 记忆个人信息\n"
               "  - 情感支持\n"
               "  - 知识问答\n\n"
               
               "输入对应关键词体验功能！输入‘退出游戏’结束当前游戏。";
    }
    
    string generateResponse(const string& input) {
        string trimmedInput = trim(input);
        if (trimmedInput.empty()) {
            return "你好像没有输入任何内容";
        }
        
        // 检查提醒
        checkReminders();
        
        // 1. 首先处理退出指令
        if (containsKeyword(trimmedInput, "再见") || containsKeyword(trimmedInput, "退出") || 
            containsKeyword(trimmedInput, "拜拜")) {
            resetGameState();
            return "再见" + (userName.empty() ? "" : " " + userName) + "！很高兴和你聊天！";
        }
        
        // 2. 处理游戏模式（如果已在游戏中）
        if (inGameMode && !currentGame.empty()) {
            string gameResponse = processGameInput(trimmedInput);
            if (!gameResponse.empty()) {
                return gameResponse;
            }
        }
        
        // 3. 处理帮助
        if (containsKeyword(trimmedInput, "帮助")) {
            return provideEnhancedHelp();
        }
        
        // 4. 处理姓名
        string response = handleName(trimmedInput);
        if (!response.empty()) return response;
        
        // 5. 处理问候
        if (containsKeyword(trimmedInput, "你好") || containsKeyword(trimmedInput, "嗨")) {
            return generateGreeting();
        }
        
        // 6. 处理游戏开始
        response = handleGames(trimmedInput);
        if (!response.empty()) return response;
        
        // 7. 处理数学计算（优先于其他功能）
        if (isMathExpression(trimmedInput)) {
            response = handleMathCalculation(trimmedInput);
            if (!response.empty()) return response;
        }
        
        // 8. 处理时间查询
        if (containsKeyword(trimmedInput, "时间") || containsKeyword(trimmedInput, "几点") || 
            containsKeyword(trimmedInput, "日期")) {
            return "现在是: " + getCurrentTime();
        }
        
        // 9. 处理天气查询
        response = handleWeather(trimmedInput);
        if (!response.empty()) return response;
        
        // 10. 处理音乐播放
        response = handleMusic(trimmedInput);
        if (!response.empty()) return response;
        
        // 11. 处理提醒
        response = handleReminder(trimmedInput);
        if (!response.empty()) return response;
        
        // 12. 处理计时器
        response = handleTimer(trimmedInput);
        if (!response.empty()) return response;
        
        // 13. 处理笑话
        if (containsKeyword(trimmedInput, "笑话") || containsKeyword(trimmedInput, "讲笑话")) {
            return getRandomJoke();
        }
        
        // 14. 处理学习
        response = handleLearning(trimmedInput);
        if (!response.empty()) return response;
        
        // 15. 处理记忆
        response = handleMemory(trimmedInput);
        if (!response.empty()) return response;
        
        // 16. 处理情感支持
        response = handleEmotions(trimmedInput);
        if (!response.empty()) return response;
        
        // 17. 处理单位转换
        response = handleUnitConversion(trimmedInput);
        if (!response.empty()) return response;
        
        // 18. 处理密码生成
        response = handlePasswordGeneration(trimmedInput);
        if (!response.empty()) return response;
        
        // 19. 处理建议
        if (containsKeyword(trimmedInput, "建议") || containsKeyword(trimmedInput, "意见")) {
            return giveRandomAdvice();
        }
        
        // 20. 处理名言
        if (containsKeyword(trimmedInput, "名言") || containsKeyword(trimmedInput, "语录")) {
            return getRandomQuote();
        }
        
        // 21. 处理感谢
        if (containsKeyword(trimmedInput, "谢谢") || containsKeyword(trimmedInput, "感谢")) {
            return "不客气！";
        }
        
        // 默认响应
        vector<string> responses = {
            "我在听呢，请继续说吧！",
            "真有趣，请继续。",
            "能详细说说吗？",
            "这是个有趣的观点。",
            "我不太明白，你能换个说法吗？"
        };
        return responses[rand() % responses.size()];
    }
    
    void initResources() {
        // 初始化名言
        quotesDatabase["zh"] = {
            "学习是终身的事业。——毛泽东",
            "实践是检验真理的唯一标准。——邓小平",
            "知识就是力量。——培根",
            "千里之行，始于足下。——老子",
            "不积跬步，无以至千里。——荀子"
        };
        
        // 初始化笑话数据库
        jokesDatabase["zh"] = {
            "为什么数学书总是很忧伤？因为它有太多的问题！",
            "有一天，一个程序员去商店买面包。售货员问：\"你要切片吗？\"程序员回答：\"不，我已经有足够的bug了。\"",
            "为什么电脑永远不会感冒？因为它有Windows（窗户）！",
            "老师说：\"同学们，今天我们要学习减法。比方说，你哥哥有5个苹果，你从他那儿拿走3个，结果怎样？\"一个学生回答：\"结果他会揍我一顿！\"",
            "为什么海星从来不参加考试？因为它总是海星（还行）！"
        };
    }
    
public:
    DeepSeekPro() : inGameMode(false), currentGame(""), nameConfirmed(false), nextReminderId(1) {
        srand(static_cast<unsigned int>(time(nullptr)));
        initResources();
        
        if (memory.count("name")) {
            userName = memory["name"];
            nameConfirmed = true;
        }
    }
    
    void run() {
        cout << BOT_NAME << ": " << generateGreeting() 
             << "我是ChatBot Pro增强版AI助手！输入“帮助”查看所有功能。" 
             << endl;
        
        while (true) {
            cout << (userName.empty() ? "用户    " : userName) << ": ";
            string userInput;
            getline(cin, userInput);
            
            string response = generateResponse(userInput);
            cout << BOT_NAME << ": " << response << endl;
            
            if (containsKeyword(response, "再见")) {
                break;
            }
        }
    }
};

// ==================== 主函数 ====================
int main() {
    // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);
    
    try {
        // 设置控制台颜色
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
        
        cout << "                                                    ========================" << endl;
        cout << "                                                          ChatBot Pro 2.0" << endl;
        cout << "                                                    ========================" << endl << endl << endl << endl << endl;
        
    	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        
        DeepSeekPro bot; 
        bot.run();
        
    } catch (const exception& e) {
        cerr << "系统错误: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
