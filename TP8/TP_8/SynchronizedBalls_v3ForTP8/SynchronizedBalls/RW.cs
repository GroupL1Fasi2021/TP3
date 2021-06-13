using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace SynchronizedBalls
{
    public class RW
    {
        private int ReadersInCS;
        private int WritersInCS;
        private readonly object lockRW = new object();

        public RW()
        {
            
        }

        public void EnterReader()
        {

            lock (lockRW)
            {

                while (WritersInCS == 1)
                {
                    Monitor.Wait(lockRW);
                }
                    
                ReadersInCS++;

            }

        }

        public void ExitReader()
        {

            lock (lockRW)
            {

                ReadersInCS--;

                if (ReadersInCS == 0)

                    Monitor.Pulse(lockRW);

            }

        }

        public void EnterWriter()
        {
            lock (lockRW)
            {

                while (WritersInCS == 1  || ReadersInCS > 0)
                {
                    Monitor.Wait(lockRW);
                }
                WritersInCS++;
            }

        }

        public void ExitWriter()
        {

            lock (lockRW)
            {

                WritersInCS--;

                Monitor.PulseAll(lockRW);

            }
 
        }

    }

}
