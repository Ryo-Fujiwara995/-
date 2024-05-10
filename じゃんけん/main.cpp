#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
// ジャンケンゲームのクラス
class JankenGame {
private:
	int playerWins; // プレイヤーの勝利回数
	int computerWins; // コンピュータの勝利回数
	int draws; // 引き分け回数
public:
	// コンストラクタ
	JankenGame() : playerWins(0), computerWins(0), draws(0) {}
	// ジャンケンをプレイする関数
	void playGame() {
		std::cout << "じゃんけんを始めますか？(はい(y)/いいえ(n)): ";
		std::string input;
		std::cin >> input;
		if (input == "はい" || input == "y") {
			for (int i = 0; i < 3; ++i) {
				playRound();
			}
			displayResult();
		}
		else {
			std::cout << "ゲームを終了します。" << std::endl;
		}
	}
private:
	// 1回のジャンケンを行う関数
	void playRound() {
		std::cout << "じゃんけんの手を選んでください。(グー/チョキ/パー): ";
		std::string playerChoice;
		std::cin >> playerChoice;
		// コンピュータの手をランダムに決定
		std::string computerChoice = getRandomChoice();
		// プレイヤーとコンピュータの手を比較して勝敗を判定
		if (playerChoice == computerChoice) {
			std::cout << "引き分けです！" << std::endl;
			++draws;
		}
		else {
			// 勝者にポイントを加算
			if (isPlayerWin(playerChoice, computerChoice)) {
				std::cout << "プレイヤー1の勝ちです！" << std::endl;
				++playerWins;
			}
			else {
				std::cout << "プレイヤー2の勝ちです！" << std::endl;
				++computerWins;
			}
		}
	}
	// コンピュータの手をランダムに決定する関数
	std::string getRandomChoice() {
		srand(time(0));
		int choice = rand() % 3;
		switch (choice) {
		case 0:
			return "グー";
		case 1:
			return "チョキ";
		case 2:
			return "パー";
		}
		//return "";
	}
	// 勝者を判定する関数
	bool isPlayerWin(const std::string& playerChoice, const std::string& computerChoice) {
		// ここでの判定ロジックを実装
		//下で数えて＋判定してるからいらない
		return 0;
	}
	// 最終的な結果を表示する関数
	void displayResult() {
		std::cout << "【自分の勝った数 対 相手の勝った数】: " << playerWins << " 対 " << computerWins << std::endl;
		std::cout << "引き分け回数: " << draws << std::endl;
	}
};

int main() {
	JankenGame janken;
	janken.playGame();
	return 0;
}


