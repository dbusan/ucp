/**
A private investigator has asked you to help develop software to analyse fingerprint
data. The software will have access to the left and right index fingerprints for a group
of people, and also a collection of unidentified prints. The investigator wishes to
know how many of the as-yet unidentified prints “possibly” or “definitely” belong to
known individuals.
Each person is identified by an integer ID, ranging from zero to the number of people
minus one. Each unidentified print is also identified by an integer ID, in the same
fashion.
The left and right fingerprint data for each person is stored in a highly-reduced /
compressed form — a “template”. Each template takes only 64 bits to store.
**/

void countMatches(int nPeople, int nPrints, int* nPossible, int* nDefinite, int (*check)(int ID, double left, double right))
{
	/** Variables to hold the values returned by getTemplates **/

//	int mPerson; 
	double mLeft, mRight;
	

	int i;
	for (i = 0 ; i < nPeople; i++)
	{
	/** Returns -1 in mLeft and mRight if no template fingerprints exist for that person **/
		getTemplates(i, &mLeft, &mRight);
	/** Skips this entire block if left and right fingerprint templates are -1 **/
		if (!(mLeft == -1 && mRight == -1))
		{		
			int j;
			for (j = 0 ; j < nPrints ; j++)
			{		
				int checkResult = *check(i, mLeft, mRight);
				if (checkResult == 1)
					*nPossible++;
				else if (checkResult == 2)
					*nDefinite++;
			}
		}
	}
}

