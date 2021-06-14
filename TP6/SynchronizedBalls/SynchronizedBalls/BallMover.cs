using System;
using System.Windows.Forms;
using System.Threading;
using System.Drawing;

namespace SynchronizedBalls
{

    /// <summary> 
    /// </summary>
    public class BallMover
    {
        private delegate void UpdatePictureBoxCallback(Point p);

        private PictureBox pb;
        Semaphore sm = new Semaphore(1,1);

        public BallMover(PictureBox pb, Semaphore sm)
        {
            this.pb = pb;
            this.sm = sm;
        }

        /// <summary> 
        /// Move ball over X axis, bouncing at the right border
        /// </summary>
        /*public void RunReader()
        {
            try
            {
                while (true)
                {
                    while (pb.Location.X < SynchronisationTestForm.CS_MINX)
                    {
                        MoveBall();
                        Thread.Sleep(10);
                    }
                    sm.WaitOne();
                    while (pb.Location.X < SynchronisationTestForm.CS_MAXX)
                    {
                        MoveBall();
                        Thread.Sleep(10);
                    }
                    sm.Release();
                    while (pb.Location.X < SynchronisationTestForm.MAXX)
                    {
                        MoveBall();
                        Thread.Sleep(10);
                    }
                    ResetBall();
                }
            }
            catch (ThreadInterruptedException)
            {
                ResetBall();
                return;
            }
        }
        public void RunWriter()
        {
            try
            {
                while (true)
                {
                    while (pb.Location.X < SynchronisationTestForm.CS_MINX)
                    {
                        MoveBall();
                        Thread.Sleep(10);
                    }
                    sm.WaitOne();
                    while (pb.Location.X < SynchronisationTestForm.CS_MAXX)
                    {
                        MoveBall();
                        Thread.Sleep(10);
                    }
                    sm.Release();
                    while (pb.Location.X < SynchronisationTestForm.MAXX)
                    {
                        MoveBall();
                        Thread.Sleep(10);
                    }
                    ResetBall();
                }
            }
            catch (ThreadInterruptedException)
            {
                ResetBall();
                return;
            }
        }*/

        /// <summary>
        /// This method moves the ball and returns the new location
        /// </summary>
        private void MoveBall()
        {
            Point p = pb.Location;
            p.X++;
            pb.Invoke(new UpdatePictureBoxCallback(MovePictureBox), p);
        }
        Random rand = new Random();
        public int RandomNumber(int min, int max)
        {
            return rand.Next(min, max);
        }
        public void RunReader()
        {
            try
            {
                while (true)
                {
                    while (pb.Location.X < SynchronisationTestForm.CS_MINX)
                    {
                        MoveBall();
                        Thread.Sleep(RandomNumber(5,10));
                    }
                    sm.WaitOne();
                    while (pb.Location.X < SynchronisationTestForm.CS_MAXX)
                    {
                        MoveBall();
                        Thread.Sleep(RandomNumber(5, 10));
                    }
                    sm.Release();
                    while (pb.Location.X < SynchronisationTestForm.MAXX)
                    {
                        MoveBall();
                        Thread.Sleep(RandomNumber(5, 10));
                    }
                    ResetBall();
                }
            }
            catch (ThreadInterruptedException)
            {
                ResetBall();
                return;
            }
        }

        public void RunWriter()
        {
             try
            {
                while (true)
                {
                    while (pb.Location.X < SynchronisationTestForm.CS_MINX)
                    {
                        MoveBall();
                        Thread.Sleep(10);
                    }
                    sm.WaitOne();
                    while (pb.Location.X < SynchronisationTestForm.CS_MAXX)
                    {
                        MoveBall();
                        Thread.Sleep(10);
                    }
                    sm.Release();
                    while (pb.Location.X < SynchronisationTestForm.MAXX)
                    {
                        MoveBall();
                        Thread.Sleep(10);
                    }
                    ResetBall();
                }
            }
            catch (ThreadInterruptedException)
            {
                ResetBall();
                return;
            }
        }
        /// <summary>
        ///  This method sets the ball back to the left hand side of the white area
        /// </summary>
        private void ResetBall()
        {
            Point p = pb.Location;
            p.X = SynchronisationTestForm.MINX;
            pb.Invoke(new UpdatePictureBoxCallback(MovePictureBox), p);
        }

        private void MovePictureBox(Point p)
        {
            pb.Location = p;
        }

    }
}