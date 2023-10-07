#include "Aleshko_bank.h"
#include "Aleshko_account.h"


std::string enterFilename()
{
    std::cout << "������� �������� ����� (��� ���������� .txt): ";
    std::string filename;
    std::cin >> filename;
    return filename + ".txt";
}

void Aleshko_bank::createAccount()
{
    std::string name, type;
    long int money;
    std::cout << "������� ��� �������: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "��� �����: ";
    std::getline(std::cin, type);
    std::cout << "����������� �����: ";
    money = GetCorrectNumber(0);
    Aleshko_account* account = new Aleshko_account(name, type, money);
    accounts.push_back(account);
}
void Aleshko_bank::displayAllAccounts() const{
    if (accounts.size())
    {
        std::cout << "��� ����� �����:" << std::endl << std::endl;
        for (const Aleshko_account* account : accounts) {
            std::cout << *account << std::endl;
        }
    }
    else
    {
        std::cout << "\n� ����� ��� ��������..." << std::endl;
    }
    
}

void Aleshko_bank::loadAllAccounts()
{
    std::string filename = enterFilename();
    std::ifstream fin(filename);
    if (fin.is_open())
    {
        int size;
        fin >> size;
        for(int i = 0; i < size; i++)
        {
            Aleshko_account account;
            fin >> account;
            Aleshko_account* acc = new Aleshko_account;
            *acc = account;
            accounts.push_back(acc);
        }
        fin.close();
    }
    else
    {
        std::cout << "���� �� ��� ������." << std::endl;
    }
}

void Aleshko_bank::saveAllAccounts()
{
    std::string filename = enterFilename();
    std::ofstream fout(filename);
    fout << accounts.size() << std::endl;
    for (const Aleshko_account* acc : accounts)
    {
        fout << *acc << std::endl;
    }

    std::cout << "������ ���� ������� ���������." << std::endl;

}

//void Aleshko_bank::clear() {
//    accounts.clear();
//}