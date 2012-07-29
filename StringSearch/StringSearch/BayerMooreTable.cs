using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StringSearch
{
    public class BadMatchTable
    {
        private readonly int _defaultValue;
        private readonly Dictionary<int, int> _distances;

        public BadMatchTable(string pattern)
        {
            _defaultValue = pattern.Length;
            _distances = new Dictionary<int, int>();

            for (int i = 0; i < pattern.Length - 1; i++)
            {
                _distances[pattern[i]] = pattern.Length - i - 1;
            }
        }

        public int this[int index]
        {
            get
            {
                int value;
                if (!_distances.TryGetValue(index, out value))
                {
                    value = _defaultValue;
                }

                return value;
            }
            set
            {
                _distances[index] = value;
            }
        }
    }
}
