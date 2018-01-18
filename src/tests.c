#include "../include/attribs.h"

int main(){
	init_code();
	print_code();
	insert_code("a", "", "", "b");
	print_code();

	label x = create_label();
	print_label(x);
	x = insert_in_label(x,5);
	print_label(x);
	label y = create_label();
	print_label(y);
	y = insert_in_label(y,6);
	print_label(y);

	label z = merge(x,y);
	print_label(z);

	expression exp;

	
}