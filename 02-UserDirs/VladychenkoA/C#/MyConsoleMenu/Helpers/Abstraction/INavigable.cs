﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Helpers.Abstraction
{
    public interface INavigable
    {
        ConsoleKey NextMenuItemKey
        {
            get;
            set;
        }

        ConsoleKey PreviousMenuItemKey
        {
            get;
            set;
        }

        ConsoleKey SelectMenuItemKey
        {
            get;
            set;
        }
    }
}
