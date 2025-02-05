﻿using HASystem.Server.Physical.Devices;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HASystem.Server.Physical.Components
{
    public class BinaryIn : PhysicalComponent
    {
        public Port Port
        {
            get;
            private set;
        }

        public BinaryIn(PhysicalDevice physicalDevice, Port port)
            : base(physicalDevice)
        {
            Port = port;
        }
    }
}