#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
// �W�����P���Q�[���̃N���X
class JankenGame {
private:
	int playerWins; // �v���C���[�̏�����
	int computerWins; // �R���s���[�^�̏�����
	int draws; // ����������
public:
	// �R���X�g���N�^
	JankenGame() : playerWins(0), computerWins(0), draws(0) {}
	// �W�����P�����v���C����֐�
	void playGame() {
		std::cout << "����񂯂���n�߂܂����H(�͂�(y)/������(n)): ";
		std::string input;
		std::cin >> input;
		if (input == "�͂�" || input == "y") {
			for (int i = 0; i < 3; ++i) {
				playRound();
			}
			displayResult();
		}
		else {
			std::cout << "�Q�[�����I�����܂��B" << std::endl;
		}
	}
private:
	// 1��̃W�����P�����s���֐�
	void playRound() {
		std::cout << "����񂯂�̎��I��ł��������B(�O�[/�`���L/�p�[): ";
		std::string playerChoice;
		std::cin >> playerChoice;
		// �R���s���[�^�̎�������_���Ɍ���
		std::string computerChoice = getRandomChoice();
		// �v���C���[�ƃR���s���[�^�̎���r���ď��s�𔻒�
		if (playerChoice == computerChoice) {
			std::cout << "���������ł��I" << std::endl;
			++draws;
		}
		else {
			// ���҂Ƀ|�C���g�����Z
			if (isPlayerWin(playerChoice, computerChoice)) {
				std::cout << "�v���C���[1�̏����ł��I" << std::endl;
				++playerWins;
			}
			else {
				std::cout << "�v���C���[2�̏����ł��I" << std::endl;
				++computerWins;
			}
		}
	}
	// �R���s���[�^�̎�������_���Ɍ��肷��֐�
	std::string getRandomChoice() {
		srand(time(0));
		int choice = rand() % 3;
		switch (choice) {
		case 0:
			return "�O�[";
		case 1:
			return "�`���L";
		case 2:
			return "�p�[";
		}
		//return "";
	}
	// ���҂𔻒肷��֐�
	bool isPlayerWin(const std::string& playerChoice, const std::string& computerChoice) {
		// �����ł̔��胍�W�b�N������
		//���Ő����ā{���肵�Ă邩�炢��Ȃ�
		return 0;
	}
	// �ŏI�I�Ȍ��ʂ�\������֐�
	void displayResult() {
		std::cout << "�y�����̏������� �� ����̏��������z: " << playerWins << " �� " << computerWins << std::endl;
		std::cout << "����������: " << draws << std::endl;
	}
};

int main() {
	JankenGame janken;
	janken.playGame();
	return 0;
}


