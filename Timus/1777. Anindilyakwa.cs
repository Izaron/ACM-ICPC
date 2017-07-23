// The solution of the problem was written by Izaron
// Date: 13:57:58   26 Apr 2015
// Execution time: 0.14

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

using System;
using System.Collections.Generic;
using System.Collections;

namespace solve
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			List<Int64> st = new List<Int64> ();
			string[] con = Console.ReadLine ().Split (' ');
			for (int i = 0; i < 3; i++) {
				Int64 value = Int64.Parse (con [i]);
				st.Add (value);
			}
			st.Sort ();

			int ans = 0;

			while (true) {
				ans++;
				Int64 min = 1000000000000000001;
				for (int i = 0; i < st.Count - 1; i++)
					if (st [i + 1] - st [i] < min) {
						min = st [i + 1] - st [i];
					}
				st.Add (min);
				st.Sort ();
				if (min == 0)
					break;
			}

			Console.Write (ans);
		}
	}
}
