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

#include <CommonAPI/CommonAPI.hpp>
#include <iostream>
#include <string>
#include <unistd.h>
#include <v1/org/genivi/vehicle/playground/PlaygroundProxy.hpp>

typedef ::org::genivi::vehicle::playgroundtypes::PlaygroundTypes::Gear Gear;

typedef ::org::genivi::vehicle::playgroundtypes::PlaygroundTypes::DriveType
    DriveType;
typedef ::org::genivi::vehicle::playgroundtypes::PlaygroundTypes::DoorsStatus
    DoorsStatus;

using namespace v1_0::org::genivi::vehicle::playground;

int main() {
  std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
  std::shared_ptr<PlaygroundProxy<>> proxy =
      runtime->buildProxy<PlaygroundProxy>("local", "1");

  std::cout << "Checking availability!" << std::endl;
  while (!proxy->isAvailable())
    usleep(10);
  std::cout << "Available..." << std::endl;

  CommonAPI::CallStatus status;

  float consumption;
  uint8_t capacity;
  float volume;
  uint16_t engineSpeed;
  Gear currentGear;
  bool isReverseGearOn;
  DriveType drivePowerTransmission;
  DoorsStatus doorsOpeningStatus;
  std::vector<bool> seatHeatingStatus;
  std::vector<uint8_t> seatHeatingLevel;

  proxy->getConsumptionAttribute().getValue(status, consumption);
  std::cout << "Fuel consumption: " << consumption << "\n";

  proxy->getCapacityAttribute().getValue(status, capacity);
  std::cout << "Tank capacity: " << (int)capacity << "\n";

  proxy->getVolumeAttribute().getValue(status, volume);
  std::cout << "Tank volume: " << volume << "\n";

  proxy->getEngineSpeedAttribute().getValue(status, engineSpeed);
  std::cout << "Engine speed: " << engineSpeed << "\n";

  proxy->getCurrentGearAttribute().getValue(status, currentGear);
  std::cout << "Current gear: " << currentGear.toString() << "\n";

  proxy->getIsReverseGearOnAttribute().getValue(status, isReverseGearOn);
  std::cout << "Reverse gear status: " << isReverseGearOn << "\n";

  proxy->getDrivePowerTransmissionAttribute().getValue(status,
                                                       drivePowerTransmission);
  std::cout << "Power transmission driver: "
            << drivePowerTransmission.toString() << "\n";

  proxy->getDoorsOpeningStatusAttribute().getValue(status, doorsOpeningStatus);
  std::cout << "\tDoors opening status: "
            << "\n";
  std::cout << "\tFront left: " << doorsOpeningStatus.getFrontLeft() << "\n";
  std::cout << "\tFront right: " << doorsOpeningStatus.getFrontRight() << "\n";
  std::cout << "\tRear left: " << doorsOpeningStatus.getRearLeft() << "\n";
  std::cout << "\tRear right: " << doorsOpeningStatus.getRearRight() << "\n";

  proxy->getSeatHeatingStatusAttribute().getValue(status, seatHeatingStatus);
  std::cout << "Seat heating status: "
            << "\n";
  std::cout << "\tDriver: " << seatHeatingStatus[0] << "\n";
  std::cout << "\tCo-Driver: " << seatHeatingStatus[1] << "\n";
  std::cout << "\tPassenger in the second row on the Driver side: "
            << seatHeatingStatus[2] << "\n";
  std::cout << "\tPassenger in the second row on the Middle side: "
            << seatHeatingStatus[3] << "\n";
  std::cout << "\tPassenger in the second row on the Co-driver side: "
            << seatHeatingStatus[4] << "\n";
  std::cout << "\tPassenger in the third row on the Driver side: "
            << seatHeatingStatus[5] << "\n";
  std::cout << "\tPassenger in the third row on the Co-driver side: "
            << seatHeatingStatus[6] << "\n";

  proxy->getSeatHeatingLevelAttribute().getValue(status, seatHeatingLevel);
  std::cout << "Seat heating level: "
            << "\n";
  std::cout << "\tDriver: " << (int)seatHeatingLevel[0] << "\n";
  std::cout << "\tCo-Driver: " << (int)seatHeatingLevel[1] << "\n";
  std::cout << "\tPassenger in the second row on the Driver side: "
            << (int)seatHeatingLevel[2] << "\n";
  std::cout << "\tPassenger in the second row on the Middle side: "
            << (int)seatHeatingLevel[3] << "\n";
  std::cout << "\tPassenger in the second row on the Co-driver side: "
            << (int)seatHeatingLevel[4] << "\n";
  std::cout << "\tPassenger in the third row on the Driver side: "
            << (int)seatHeatingLevel[5] << "\n";
  std::cout << "\tPassenger in the third row on the Co-driver side: "
            << (int)seatHeatingLevel[6] << "\n";

  proxy->getCurrentTankVolumeEvent().subscribe([&](const int8_t &val) {
    std::cout << "Current tank level from subscription: " << (int)val
              << std::endl;
  });
  // wait for subscription
  usleep(500000);
}
