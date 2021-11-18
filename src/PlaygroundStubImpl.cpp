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

#include "PlaygroundStubImpl.hpp"
#include "MockedValues.hpp"
#include <bits/stdint-uintn.h>
#include <csignal>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <sys/types.h>

typedef v1_0::org::genivi::vehicle::playground::PlaygroundStubDefault
    PlaygroundStubDefault;

const double CAPACITY_MIN_VALUE = 0.0;
const double CAPACITY_MAX_VALUE = 255.0;
const double CAPACITY_MAX_VALUE_IN_LITERS = 80.0;

bool getNextStateFromCommand(const bool &currentState,
                             const DoorCommand &command) {
  if (command == DoorCommand::Literal::NOTHING) {
    return currentState;
  }
  return (command == DoorCommand::Literal::OPEN_DOOR);
}

PlaygroundStubImpl::PlaygroundStubImpl() { initializeAttributes(); }
PlaygroundStubImpl::~PlaygroundStubImpl() {}

void PlaygroundStubImpl::initializeAttributes() {
  PlaygroundStubDefault::setConsumptionAttribute(MockedValues::CONSUMPTION);
  PlaygroundStubDefault::setCapacityAttribute(MockedValues::CAPACITY);
  PlaygroundStubDefault::setVolumeAttribute(MockedValues::VOLUME);
  PlaygroundStubDefault::setEngineSpeedAttribute(MockedValues::ENGINE_SPEED);
  PlaygroundStubDefault::setCurrentGearAttribute(MockedValues::CURRENT_GEAR);
  PlaygroundStubDefault::setIsReverseGearOnAttribute(
      MockedValues::IS_REVERSE_GEAR_ON);
  PlaygroundStubDefault::setDrivePowerTransmissionAttribute(
      MockedValues::DRIVE_POWER_TRANSMISSION);
  PlaygroundStubDefault::setDoorsOpeningStatusAttribute(
      MockedValues::DOORS_OPENING_STATUS);
  PlaygroundStubDefault::setSeatHeatingStatusAttribute(
      MockedValues::SEAT_HEATING_STATUS);
  PlaygroundStubDefault::setSeatHeatingLevelAttribute(
      MockedValues::SEAT_HEATING_LEVEL);
}

void PlaygroundStubImpl::monitorTankLevel() {
  const int capacityAttribute =
      PlaygroundStubDefault::getCapacityAttribute();
  const double capacity =
      CAPACITY_MAX_VALUE_IN_LITERS *
      (capacityAttribute / (CAPACITY_MAX_VALUE - CAPACITY_MIN_VALUE));
  const int currentVolume = PlaygroundStubDefault::getVolumeAttribute();
  const uint8_t &level = (uint8_t)(100 * currentVolume / capacity);
  fireCurrentTankVolumeEvent(level);
}

void PlaygroundStubImpl::changeDoorsState(
    const std::shared_ptr<CommonAPI::ClientId> _client,
    CarDoorsCommand _commands, changeDoorsStateReply_t _reply) {

  DoorsStatus lockedDoorsStatus =
      PlaygroundStubDefault::getDoorsOpeningStatusAttribute();

  const bool &currentFrontLeftState = lockedDoorsStatus.getFrontLeft();
  const bool &currentFrontRightState = lockedDoorsStatus.getFrontRight();
  const bool &currentRearLeftState = lockedDoorsStatus.getRearLeft();
  const bool &currentRearRightState = lockedDoorsStatus.getRearRight();

  const DoorCommand &frontLeftCommand = _commands.getFrontLeftDoor();
  const DoorCommand &frontRightCommand = _commands.getFrontRightDoor();
  const DoorCommand &rearLeftCommand = _commands.getRearLeftDoor();
  const DoorCommand &rearRightCommand = _commands.getRearRightDoor();

  const bool &nextFrontLeftState =
      getNextStateFromCommand(currentFrontLeftState, frontLeftCommand);
  const bool &nextFrontRightState =
      getNextStateFromCommand(currentFrontRightState, frontRightCommand);
  const bool &nextRearLeftState =
      getNextStateFromCommand(currentRearLeftState, rearLeftCommand);
  const bool &nextRearRightState =
      getNextStateFromCommand(currentRearRightState, rearRightCommand);

  const DoorsStatus &doorsStatus =
      DoorsStatus(nextFrontLeftState, nextFrontRightState, nextRearLeftState,
                  nextRearRightState);

  PlaygroundStubDefault::setDoorsOpeningStatusAttribute(doorsStatus);
  _reply();
};
