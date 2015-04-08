#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <QString>

class Exception
{
public:
    explicit Exception(const QString& message) : m_message(message) {}
    QString what() const {
        return m_message;
    }
private:
    QString m_message;
};

#endif // _EXCEPTION_H_
