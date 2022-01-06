/*
 * Copyright (C) 2021, Bayerische Motoren Werke Aktiengesellschaft (BMW AG),
 *   Author: Alexander Domin (Alexander.Domin@bmw.de)
 * Copyright (C) 2021, ProFUSION Sistemas e Soluções LTDA,
 *   Author: Leandro Ferlin (leandroferlin@profusion.mobi)
 *
 * SPDX-License-Identifier: MPL-2.0
 *
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a copy of the MPL was
 * not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */

typedef ::org::genivi::vehicle::playgroundtypes::PlaygroundTypes::Gear Gear;

typedef ::org::genivi::vehicle::playgroundtypes::PlaygroundTypes::DriveType
    DriveType;
typedef ::org::genivi::vehicle::playgroundtypes::PlaygroundTypes::DoorsStatus
    DoorsStatus;

namespace MockedValues {

float CONSUMPTION = 4.5;
uint8_t CAPACITY = 200;
float VOLUME = 60.0;
uint16_t ENGINE_SPEED = 2000;
Gear CURRENT_GEAR = Gear(Gear::Literal::FOURTH_GEAR);
bool IS_REVERSE_GEAR_ON = false;
DriveType DRIVE_POWER_TRANSMISSION =
    DriveType(DriveType::Literal::REAR_WHEEL_DRIVE);
DoorsStatus DOORS_OPENING_STATUS = DoorsStatus(true, false, false, false);
std::vector<bool> SEAT_HEATING_STATUS = {true,  true, false, true,
                                         false, true, false};
std::vector<uint8_t> SEAT_HEATING_LEVEL = {50, 45, 30, 30, 60, 65, 70};

} // namespace MockedValues
