#pragma once

#include <QDialog>
#include <QString>
#include <QHBoxLayout>
#include <QLabel>
#include <QVariant>
#include <QFont>

class HelpMenu : public QDialog
{
public:
    explicit HelpMenu(QWidget* pParent = nullptr);

private:
    QHBoxLayout* makePairWidgets(QWidget* pLeftWidget, QWidget* pRightWidget) const;


    QHBoxLayout *makeDescription(const QVariant& crVar, const QString& crQstrTxt);
    void AdjustHelpMenu();
};

