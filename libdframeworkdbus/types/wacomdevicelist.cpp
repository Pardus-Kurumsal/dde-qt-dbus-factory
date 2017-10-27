#include "wacomdevicelist.h"

bool WacomDevice::operator ==(const WacomDevice &device)
{
    return this->deviceType == device.deviceType && this->interface == device.interface;
}

QDBusArgument &operator<<(QDBusArgument &argument, const WacomDevice &device)
{
    argument.beginStructure();
    argument << device.interface << device.deviceType;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, WacomDevice &device)
{
    argument.beginStructure();
    argument >> device.interface >> device.deviceType;
    argument.endStructure();
    return argument;
}

void registerWacomDeviceListMetaType()
{
    qRegisterMetaType<WacomDevice>("WacomDevice");
    qDBusRegisterMetaType<WacomDevice>();

    qRegisterMetaType<WacomDeviceList>("WacomDeviceList");
    qDBusRegisterMetaType<WacomDeviceList>();
}
