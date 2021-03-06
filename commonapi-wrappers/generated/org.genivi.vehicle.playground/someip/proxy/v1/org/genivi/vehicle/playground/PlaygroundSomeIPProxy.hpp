/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#ifndef V1_ORG_GENIVI_VEHICLE_PLAYGROUND_PLAYGROUND_SOMEIP_PROXY_HPP_
#define V1_ORG_GENIVI_VEHICLE_PLAYGROUND_PLAYGROUND_SOMEIP_PROXY_HPP_

#include <v1/org/genivi/vehicle/playground/PlaygroundProxyBase.hpp>
#include <org/genivi/vehicle/playgroundtypes/PlaygroundTypesSomeIPDeployment.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Proxy.hpp>
#include <CommonAPI/SomeIP/Types.hpp>
#include <CommonAPI/SomeIP/Attribute.hpp>
#include <CommonAPI/SomeIP/Event.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <string>

# if defined(_MSC_VER)
#  if _MSC_VER >= 1300
/*
 * Diamond inheritance is used for the CommonAPI::Proxy base class.
 * The Microsoft compiler put warning (C4250) using a desired c++ feature: "Delegating to a sister class"
 * A powerful technique that arises from using virtual inheritance is to delegate a method from a class in another class
 * by using a common abstract base class. This is also called cross delegation.
 */
#    pragma warning( disable : 4250 )
#  endif
# endif

namespace v1 {
namespace org {
namespace genivi {
namespace vehicle {
namespace playground {

class PlaygroundSomeIPProxy
    : virtual public PlaygroundProxyBase,
      virtual public CommonAPI::SomeIP::Proxy {
public:
    PlaygroundSomeIPProxy(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection);

    virtual ~PlaygroundSomeIPProxy();

    virtual ConsumptionAttribute& getConsumptionAttribute();

    virtual CapacityAttribute& getCapacityAttribute();

    virtual VolumeAttribute& getVolumeAttribute();

    virtual EngineSpeedAttribute& getEngineSpeedAttribute();

    virtual CurrentGearAttribute& getCurrentGearAttribute();

    virtual IsReverseGearOnAttribute& getIsReverseGearOnAttribute();

    virtual DrivePowerTransmissionAttribute& getDrivePowerTransmissionAttribute();

    virtual DoorsOpeningStatusAttribute& getDoorsOpeningStatusAttribute();

    virtual SeatHeatingStatusAttribute& getSeatHeatingStatusAttribute();

    virtual SeatHeatingLevelAttribute& getSeatHeatingLevelAttribute();

    virtual VehiclePositionEvent& getVehiclePositionEvent();

    virtual CurrentTankVolumeEvent& getCurrentTankVolumeEvent();

    /*
     * description: 
     * Trigger tire pressure initialization process
     */
    virtual void initTirePressureCalibration(CommonAPI::CallStatus &_internalCallStatus, const CommonAPI::CallInfo *_info);

    virtual std::future<CommonAPI::CallStatus> initTirePressureCalibrationAsync(InitTirePressureCalibrationAsyncCallback _callback, const CommonAPI::CallInfo *_info);

    /*
     * description: 
     * Trigger the change on doors opening state
     */
    virtual void changeDoorsState(::org::genivi::vehicle::playgroundtypes::PlaygroundTypes::CarDoorsCommand _commands, CommonAPI::CallStatus &_internalCallStatus, const CommonAPI::CallInfo *_info);

    virtual std::future<CommonAPI::CallStatus> changeDoorsStateAsync(const ::org::genivi::vehicle::playgroundtypes::PlaygroundTypes::CarDoorsCommand &_commands, ChangeDoorsStateAsyncCallback _callback, const CommonAPI::CallInfo *_info);

    virtual void getOwnVersion(uint16_t &_major, uint16_t &_minor) const;

    virtual std::future<void> getCompletionFuture();

private:
    CommonAPI::SomeIP::ObservableAttribute<CommonAPI::SomeIP::ReadonlyAttribute<ConsumptionAttribute>> consumption_;
    CommonAPI::SomeIP::ReadonlyAttribute<CapacityAttribute, CommonAPI::SomeIP::IntegerDeployment<uint8_t>> capacity_;
    CommonAPI::SomeIP::ReadonlyAttribute<VolumeAttribute> volume_;
    CommonAPI::SomeIP::ObservableAttribute<CommonAPI::SomeIP::ReadonlyAttribute<EngineSpeedAttribute, CommonAPI::SomeIP::IntegerDeployment<uint16_t>>> engineSpeed_;
    class SomeIPcurrentGear_Attribute : public CommonAPI::SomeIP::ObservableAttribute<CommonAPI::SomeIP::ReadonlyAttribute<CurrentGearAttribute, ::org::genivi::vehicle::playgroundtypes::PlaygroundTypes_::GearDeployment_t>> {
    public:
        template <typename... _A>
            SomeIPcurrentGear_Attribute(PlaygroundSomeIPProxy &_proxy,
                _A ... arguments) : CommonAPI::SomeIP::ObservableAttribute<CommonAPI::SomeIP::ReadonlyAttribute<CurrentGearAttribute, ::org::genivi::vehicle::playgroundtypes::PlaygroundTypes_::GearDeployment_t>>(
                                        _proxy, arguments...) {}
    };
    SomeIPcurrentGear_Attribute currentGear_;

    CommonAPI::SomeIP::ObservableAttribute<CommonAPI::SomeIP::ReadonlyAttribute<IsReverseGearOnAttribute>> isReverseGearOn_;
    class SomeIPdrivePowerTransmission_Attribute : public CommonAPI::SomeIP::ObservableAttribute<CommonAPI::SomeIP::ReadonlyAttribute<DrivePowerTransmissionAttribute, ::org::genivi::vehicle::playgroundtypes::PlaygroundTypes_::DriveTypeDeployment_t>> {
    public:
        template <typename... _A>
            SomeIPdrivePowerTransmission_Attribute(PlaygroundSomeIPProxy &_proxy,
                _A ... arguments) : CommonAPI::SomeIP::ObservableAttribute<CommonAPI::SomeIP::ReadonlyAttribute<DrivePowerTransmissionAttribute, ::org::genivi::vehicle::playgroundtypes::PlaygroundTypes_::DriveTypeDeployment_t>>(
                                        _proxy, arguments...) {}
    };
    SomeIPdrivePowerTransmission_Attribute drivePowerTransmission_;

    CommonAPI::SomeIP::ObservableAttribute<CommonAPI::SomeIP::ReadonlyAttribute<DoorsOpeningStatusAttribute, ::org::genivi::vehicle::playgroundtypes::PlaygroundTypes_::DoorsStatusDeployment_t>> doorsOpeningStatus_;
    CommonAPI::SomeIP::ObservableAttribute<CommonAPI::SomeIP::Attribute<SeatHeatingStatusAttribute, CommonAPI::SomeIP::ArrayDeployment< CommonAPI::EmptyDeployment >>> seatHeatingStatus_;
    CommonAPI::SomeIP::ObservableAttribute<CommonAPI::SomeIP::Attribute<SeatHeatingLevelAttribute, CommonAPI::SomeIP::ArrayDeployment< CommonAPI::SomeIP::IntegerDeployment<uint8_t> >>> seatHeatingLevel_;
    CommonAPI::SomeIP::Event<VehiclePositionEvent, CommonAPI::Deployable< ::org::genivi::vehicle::playgroundtypes::PlaygroundTypes::StatusGPS, ::org::genivi::vehicle::playgroundtypes::PlaygroundTypes_::StatusGPSDeployment_t >> vehiclePosition_;
    CommonAPI::SomeIP::Event<CurrentTankVolumeEvent, CommonAPI::Deployable< uint8_t, CommonAPI::SomeIP::IntegerDeployment<uint8_t> >> currentTankVolume_;

    std::promise<void> completed_;
};

} // namespace playground
} // namespace vehicle
} // namespace genivi
} // namespace org
} // namespace v1

#endif // V1_ORG_GENIVI_VEHICLE_PLAYGROUND_Playground_SOMEIP_PROXY_HPP_
