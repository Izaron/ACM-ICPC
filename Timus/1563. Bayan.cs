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
