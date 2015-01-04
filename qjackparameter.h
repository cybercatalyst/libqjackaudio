///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    This file is part of QJackAudio.                                       //
//    Copyright (C) 2015 Jacob Dawid, jacob@omg-it.works                     //
//                                                                           //
//    QJackAudio is free software: you can redistribute it and/or modify     //
//    it under the terms of the GNU General Public License as published by   //
//    the Free Software Foundation, either version 3 of the License, or      //
//    (at your option) any later version.                                    //
//                                                                           //
//    QJackAudio is distributed in the hope that it will be useful,          //
//    but WITHOUT ANY WARRANTY; without even the implied warranty of         //
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          //
//    GNU General Public License for more details.                           //
//                                                                           //
//    You should have received a copy of the GNU General Public License      //
//    along with QJackAudio. If not, see <http://www.gnu.org/licenses/>.     //
//                                                                           //
//    It is possible to obtain a closed-source license of QJackAudio.        //
//    If you're interested, contact me at: jacob@omg-it.works                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#pragma once

// JACK includes
typedef struct jackctl_parameter jackctl_parameter_t;

// Qt includes
#include <QString>
class QVariant;

class QJackParameter
{
    friend class QJackServerControl;
public:
    enum ParameterType {
        ParameterTypeInt,
        ParameterTypeUInt,
        ParameterTypeChar,
        ParameterTypeString,
        ParameterTypeBool
    };

    QString name();
    QString shortDescription();
    QString longDescription();
    ParameterType type();

    /** @returns true, if this parameters has been set, false otherwise. */
    bool isSet();
    bool reset();

    QVariant value();
    bool setValue(QVariant value);

private:
    QJackParameter(jackctl_parameter_t *parameter);

    jackctl_parameter_t *_jackParameter;
};