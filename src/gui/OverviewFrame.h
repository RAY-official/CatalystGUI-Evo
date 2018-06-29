#pragma once

#include <QFrame>
#include <QStyledItemDelegate>

namespace Ui {
class OverviewFrame;
}

namespace WalletGui {

class RecentTransactionsModel;

class OverviewFrame : public QFrame {
  Q_OBJECT
  Q_DISABLE_COPY(OverviewFrame)

public:
  OverviewFrame(QWidget* _parent);
  ~OverviewFrame();

private:
  QScopedPointer<Ui::OverviewFrame> m_ui;
  QSharedPointer<RecentTransactionsModel> m_transactionModel;

  void transactionsInserted(const QModelIndex& _parent, int _first, int _last);
  void transactionsRemoved(const QModelIndex& _parent, int _first, int _last);
  void layoutChanged();
  void updateActualBalance(quint64 _balance);
  void updatePendingBalance(quint64 _balance);
  void actualDepositBalanceUpdated(quint64 _balance);
  void pendingDepositBalanceUpdated(quint64 _balance);
  void reset();
};

}