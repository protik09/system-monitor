/*
 * Copyright (C) 2017 Lily Rivers (VioletDarkKitty)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License only.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#ifndef TABLEMEMORYITEM_H
#define TABLEMEMORYITEM_H
#include "memoryconversion.h"
#include <QString>
using namespace memoryConversion;

class TableMemoryItem : public QTableWidgetItem
{
public:
    TableMemoryItem(memoryUnit u=memoryUnit::b, double v=0)
        :QTableWidgetItem(calculateTxt(u,v))
    {
        if (v==0) {
            // if we set the string as N/A using calculateTxt, set the unit
            // to be as low as possible
            unit = memoryUnit::b; // the lowest enum value
        } else {
            unit = u;
        }
        value = v;
    }
    bool operator <(const QTableWidgetItem &other) const
    {
        // return true if other is greater than this
        if (other.text() == "N/A") { return false; }
        const TableMemoryItem& otherMemoryItem = dynamic_cast<const TableMemoryItem&>(other);
        memoryUnit otherUnit = otherMemoryItem.unit;
        double otherValue = otherMemoryItem.value;

        if (lookupUnit(unit) < lookupUnit(otherUnit)) { return true; }
        if (lookupUnit(unit) > lookupUnit(otherUnit)) { return false; }
        // must be equal, return the bigger of the 2 values

        return value < otherValue;
    }
protected:
    memoryUnit unit;
    double value;
private:
    static QString calculateTxt(memoryUnit u=memoryUnit::b, double v=0) {
        // used for setting the string shown in the table
        // a value of 0 means we can't read it so show N/A like gnome does
        if (v>0.0) {
            return  QString::fromStdString(dbl2str(v)) + " " + QString::fromStdString(unitToString(u));
        }
        return "N/A";
    }
};

#endif // TABLEMEMORYITEM_H

