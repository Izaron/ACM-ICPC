// The solution of the problem was written by Izaron
// Date: 13:45:40   26 Apr 2015
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
			Dictionary<string, bool> dict = new Dictionary<string, bool> ();
			int n = Convert.ToInt16 (Console.ReadLine ()), ans = 0;
			for (int i = 0; i < n; i++) {
				string s = Console.ReadLine ();
				if (dict.ContainsKey (s))
					ans++;
				else
					dict.Add (s, true);
			}
			Console.WriteLine (ans);
		}
	}
}
