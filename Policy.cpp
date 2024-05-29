#include "Policy.h"

#include <QString>

#include <algorithm>
#include <stdexcept>

std::map<Keys, std::string> mapPolicy =
{
    {Keys::key_Id, QString::fromLocal8Bit("����� ������").toStdString()},
    {Keys::key_fullName, QString::fromLocal8Bit("��� ������������").toStdString()},
    {Keys::key_telNumber, QString::fromLocal8Bit("����� ��������").toStdString()},
    {Keys::key_typeOfHouse, QString::fromLocal8Bit("��� ������").toStdString()},
    {Keys::key_address, QString::fromLocal8Bit("�����").toStdString()},
    {Keys::key_typeOfProperty, QString::fromLocal8Bit("��������").toStdString()},
    {Keys::key_yearOfConstruction, QString::fromLocal8Bit("��� ���������").toStdString()},
    {Keys::key_housingArea, QString::fromLocal8Bit("������� ����").toStdString()},
    {Keys::key_insuranceProgram, QString::fromLocal8Bit("���������").toStdString()},
    {Keys::key_insuranceAmount, QString::fromLocal8Bit("����� �����������").toStdString()},
    {Keys::key_insurancePremium, QString::fromLocal8Bit("��������� ������").toStdString()},
    {Keys::key_insurancePeriod, QString::fromLocal8Bit("���� �����������").toStdString()}
};

Policy::Policy()
{
    for(const auto& pair : mapPolicy)
    {
        m_vDataRow.push_back("");
    }
}

bool Policy::isValid() const
{
    if(m_vDataRow.empty())
        return false;
    return true;
}

void Policy::setDataToColumn(const std::string& crStrData, unsigned int iColumn)
{
    m_vDataRow.at(iColumn) = crStrData;
}

void Policy::setData(const std::vector<std::string>& vData)
{
    int iColumn{0};
    for(const auto& data : vData)
    {
        m_vDataRow[iColumn] = data;
        ++iColumn;
    }
}



std::string Policy::getDataFromKey(Keys key) const
{
    try
    {
        if(!m_vDataRow.empty())
            return m_vDataRow.at(static_cast<int>(key));
    }
    catch(std::bad_alloc&)
    {
        return "";
    }
    catch(std::out_of_range&)
    {
        return "";
    }
    return "";
}

std::map<Keys, std::string> Policy::getTypes()
{
    return mapPolicy;
}

std::string Policy::getHeaderFromKey(Keys key) const
{
    return mapPolicy[key];
}

std::vector<std::string> Policy::getRowData() const
{

    return m_vDataRow;
}
