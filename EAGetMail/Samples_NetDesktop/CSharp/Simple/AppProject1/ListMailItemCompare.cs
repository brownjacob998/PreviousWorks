using System;
using System.Collections;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AppProject1
{
    class ListMailItemCompare: IComparer
    {
        // Sort the email as received data.
        public int Compare(object x, object y)
        {
            ListViewItem itemx = x as ListViewItem;
            ListViewItem itemy = y as ListViewItem;

            string sx = itemx.SubItems[2].Text;
            string sy = itemy.SubItems[2].Text;
            if (sx.Length != sy.Length)
                return -1; //should never occured.

            int count = sx.Length;
            for (int i = 0; i < count; i++)
            {
                if (sx[i] > sy[i])
                    return -1;
                else if (sx[i] < sy[i])
                    return 1;
            }

            return 0;
        }
    }
}
