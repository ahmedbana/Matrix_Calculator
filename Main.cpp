#include <iostream>
#include <string>
using namespace std; 
class matrix
{ 

	int** mat;
	int nrow;
	int ncolumn;
public:
	int getrow()
	{
		return nrow;
	}
	int getcolumn()
	{
		return ncolumn;
	}
	void create_matrix(int rows, int columns)
{
	/*
	A dynamic 2D array is basically an array of pointers to arrays.
	First, we will allocate memory for an array which contains a set of pointers.
	Next, we will allocate memory for each array which is pointed by the pointers.
	The deallocation of memory is done in the reverse order of memory allocation.
	*/
	this->mat = new int* [rows];
	
	for (int i = 0; i < rows; i++)
	{
		mat[i] = new int[columns];
	}

	
}
	void fill(int **mat, int ro, int co , int var  )
	{
		mat[ro][co]=var;
		
	}
	void breakit(string input)
	{
		input = input.substr(input.find('[')+1);

		for(int i=0;i<this->nrow;i++)
		{
			
			if ( i > 0 )
			{
		input = input.substr(1);
			input = input.substr(input.find(' '));
			}
			//cout<<input<<endl;
			for(int j=0;j<this->ncolumn;j++)
			{
				
				char *token;
				char *text;
				text=&input[0]; // *text= input;
				//if ( i >0 ) 
					//text=&input[1]; 
				if ( j==0 ) 
				token= strtok(text, " ");
				
				else if ( j == this->ncolumn -1 ) {
			    if ( i == this->nrow-1 ) {
				token=strtok(NULL ,  "]" );
				}
				else
				token=strtok(NULL ,  ";" );
				
				}
				
				else 
				token=strtok(NULL , " ");
				//cout<<token<<endl;

				this->mat[i][j]= atof(token);
				//this->fill(this->mat , i , j , atof(token)) ;
			
			}
			
		}

	}
	void dimension ( string input ) 
	{ 
		this->nrow=1;
		this->ncolumn=1;
		for ( int i =0 ; i<input.length(); i++)
		{
			
			if (input [i] == ';')
				this->nrow++;
		}
		for ( int i =0 ; i<input.length(); i++)
		{
			int start = input.find('[');

			if ( (input[i] == ' ') && (i >start)) 
				this->ncolumn++;
				if ( (input[i]==';')|| (input[i] == ']'))
				break;
			
		}
	

}
	void print_matrix()
{
	
	for (int i = 0; i < this->nrow; i++)
	{
		for (int j = 0; j < this->ncolumn; j++)
		{
			cout<<this->mat[i][j]<<"\t";
		}
		cout << endl;
	}

}
	void destroy()
{
	for (int i = 0; i < this->nrow; i++)
	{
		delete[] this->mat[i]; //deletes an inner array of integer;
	}

	delete[] this->mat; //delete pointer holding array of pointers;
}

};

int main()
{
	string input;
	getline (cin , input);
	matrix a;
	a.dimension(input);
	a.create_matrix(a.getrow() , a.getcolumn() );
	//cout<<a.getrow()<<endl;
	//cout<<a.getcolumn()<<endl;
	a.breakit(input);
	a.print_matrix();
	a.destroy(); 

	while (1) ;
	return 0;
}
