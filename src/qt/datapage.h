// Copyright (c) 2018 Slawek Mozdzonek
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_DATAPAGE_H
#define BITCOIN_QT_DATAPAGE_H

#include <policy/feerate.h>
#include <qt/walletmodel.h>

#include <QFile>
#include <QWidget>
#include <univalue.h>

class WalletModel;
class ClientModel;
class QPlainTextEdit;
class PlatformStyle;
class QButtonGroup;

namespace Ui {
    class DataPage;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

class DataPage : public QWidget
{
    Q_OBJECT

public:
    explicit DataPage(const PlatformStyle *platformStyle, QWidget *parent = 0);
    ~DataPage();

    void setClientModel(ClientModel *clientModel);
    void setModel(WalletModel *model);

private:
    Ui::DataPage *ui;
    WalletModel *walletModel;
    ClientModel *clientModel;
    const int blockSizeDisplay;
    std::string changeAddress;
    bool fFeeMinimized;
    CFeeRate feeRate;
    QString hexaValue;
    QString textValue;
    QString fileToRetrieveName;
    QString fileToStoreName;
    QString fileToCheckName;
    QButtonGroup *groupFee;

    void displayInBlocks(QPlainTextEdit* textEdit, const QString& inStr, int blockSize);
    void unlockWallet();
    std::string computeHash(QByteArray binaryData);
    std::string getHexStr();
    void minimizeFeeSection(bool fMinimize);
    void updateFeeMinimizedLabel();
    void updateCoinControlState(CCoinControl& ctrl);

public Q_SLOTS:
    void setBalance(const interfaces::WalletBalances& balances);

private Q_SLOTS:
    void retrieve();
    void store();
    void check();
    void hexRadioClicked();
    void stringRadioClicked();
    void fileRetrieveClicked();
    void safeToFileToggled(bool);
    void fileStoreClicked();    
    void storeMessageRadioClicked();
    void storeFileRadioClicked();
    void storeFileHashRadioClicked();
    void checkMessageRadioClicked();
    void checkFileRadioClicked();
    void checkFileHashRadioClicked();
    void fileCheckClicked();
    
    void on_buttonChooseFee_clicked();
    void on_buttonMinimizeFee_clicked();
    void setMinimumFee();
    void updateFeeSectionControls();
    void updateMinFeeLabel();
    void updateSmartFeeLabel();
    void updateDisplayUnit();
    
private:
    class FileWriter
    {
    public:
        FileWriter(const QString& fileName);
        ~FileWriter();
        void write(const QByteArray &byteArray);

    private:
        bool isOpen;
        QFile file;	
    };

    class FileReader
    {
    public:
        FileReader(const QString& fileName);
        ~FileReader();
        void read(QByteArray &byteArray);

    private:
        bool isOpen;
        QFile file;	
    };
};

#endif // BITCOIN_QT_DATAPAGE_H