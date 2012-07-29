using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StringSearch
{

    public class BMHSearch
    {
        public IEnumerable<int> Search(string pattern, string toSearch)
        {
            if (pattern == null)
            {
                throw new ArgumentNullException("toFind");
            }

            if (toSearch == null)
            {
                throw new ArgumentNullException("toSearch");
            }

            if (pattern.Length > 0 && toSearch.Length > 0)
            {
                BadMatchTable badMatchTable = new BadMatchTable(pattern);

                int currentStartIndex = 0;
                while (currentStartIndex <= toSearch.Length - pattern.Length)
                {
                    int charactersLeftToMatch = pattern.Length - 1;

                    while (charactersLeftToMatch >= 0 &&
                           Compare(pattern[charactersLeftToMatch], toSearch[currentStartIndex + charactersLeftToMatch]) == 0)
                    {
                        charactersLeftToMatch--;
                    }

                    if (charactersLeftToMatch < 0)
                    {
                        yield return currentStartIndex;
                        currentStartIndex += pattern.Length;
                    }
                    else
                    {
                        currentStartIndex += badMatchTable[toSearch[currentStartIndex + pattern.Length - 1]];
                    }
                }
            }
        }
    }
}
