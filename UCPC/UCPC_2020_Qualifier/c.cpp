#include <cstdio>
#include <cctype>
#include <cmath>
#include <cassert>

// Types
const char VAR = 'v'; // a
const char BOOL = 'c'; // 0|1
const char Q = '?'; // ?
const char END = ':'; // :
const char MATCH = 'm'; // a==b
const char ASSIGN = 'a'; // a==1

struct token {
	char type;
	char var; // in index
	char other_var; // in index
	char b; // 0 | 1
};

// Global values
int vars = 0; // 1...26
int d = 0; // depth seeker
int t = 0; // token seeker
token tokens[1000] = { 0 };

// Memory
int P[27][1000] = { 0 }; // parent (negative if inverse)
int B[27][1000] = { 0 }; // assigned boolean (of parent)
int V[1000] = { 0 }; // valid

int select();

int terminate() {
	if (!V[d]) {
		/// printf("NONO TERM\n");
		return 0;
	} else {
		///	printf("GO TERM\n");
	}

	int choices = 1;
	for (int i = 1; i <= vars; ++i) {
		if (P[d][i] == i && B[d][i] == -1)
			choices *= 2;
	}

	/// printf("TERM %d\n", choices);
	return choices;
}

int match(int var0, int var1, bool inverse, bool terminal) {
	// Assign new parent to me and assign my value to parent
	int old_p = P[d][var0];
	int new_p = inverse ? -P[d][var1] : P[d][var1];
	int old_b = B[d][abs(old_p)];
	int new_b = B[d][abs(new_p)];
	if (old_b != -1 && old_p < 0) old_b = !old_b;
	if (new_b != -1 && new_p < 0) new_b = !new_b;

	bool parent_conflict = (old_p == - new_p);
	bool value_conflict = (old_b == 0 && new_b == 1) || (old_b == 1 && new_b == 0);
	/// printf("VAR0: %d VAR1: %d\n", var0, var1);
	/// printf("OLD P: %d NEW P: %d\n", old_p, new_p);
	/// printf("PARENT CONF %d VALUE CONF %d\n", parent_conflict, value_conflict);
	if (parent_conflict || value_conflict) {
		V[d] = 0;
	} else {
		P[d][var0] = new_p; // assign new parent to current
		if (old_b != -1) { // assign my value to new parent
			if (new_p > 0) B[d][abs(new_p)] = old_b; // follow parent
			else           B[d][abs(new_p)] = !old_b; // invert parent
		}
	}

	if (terminal) return terminate();
	else return select();
}

int assign(int var0, int b, bool terminal) {
	int parent = P[d][var0];
	int old_b = B[d][abs(parent)];
	int new_b = parent > 0 ? b : !b;

	if ((old_b == 0 && new_b == 1) || (old_b == 1 && new_b == 0)) {
		V[d] = 0;
	} else {
		B[d][abs(parent)] = new_b;
	}

	if (terminal) return terminate();
	else return select();
}

int skip(bool valid, bool terminal) { // e.g., 0 ? a : b
	V[d] *= valid;
	if (terminal) return terminate();
	else return select();
}

void refresh_memory() {
	// copy over memory from previous depth
	for (int i = 1; i <= vars; ++i) {
		P[d][i] = P[d - 1][i];
		B[d][i] = B[d - 1][i];
	}
	V[d] = V[d - 1];
}

int select() {
	token current = tokens[t++];
	bool terminate = tokens[t++].type == END;

	/// printf("SELECTING TOKEN %c AT DEPTH %d (%s)\n", current.type, d, terminate ? "TERMINAL" : "ONGOING");
	d += 1;
	refresh_memory();

	int choices = 0;
	switch (current.type) {
		case VAR:
			if (terminate) {
				choices += assign(current.var, 0, true);
			} else {
				choices += assign(current.var, 1, false);
				refresh_memory();
				choices += assign(current.var, 0, false);
			}
			break;
		case BOOL:
			if (terminate) {
				choices += skip(current.b == 0, true);
			} else {
				choices += skip(current.b == 1, false);
				refresh_memory();
				choices += skip(current.b == 0, false);
			}
			break;
		case MATCH:
			if (terminate) {
				choices += match(current.var, current.other_var, false, true);
			} else {
				/// printf("MATCHING %c %c\n", current.var + 'a' - 1, current.other_var + 'a' - 1);
				choices += match(current.var, current.other_var, true, false);
				refresh_memory();
				choices += match(current.var, current.other_var, false, false);
			}
			break;
		case ASSIGN:
			if (terminate) {
				choices += assign(current.var, !current.b, true);
			} else {
				choices += assign(current.var, current.b, false);
				refresh_memory();
				choices += assign(current.var, !current.b, false);
			}
			break;
	}

	d -= 1;
	return choices;
}


int main(void) {
	scanf("%d", &vars);
	scanf("%*c");

	// get line
	int i = -1;
	char line[1001];
	do {
		line[++i] = getchar();
	} while (line[i] && line[i] != '\n');

	if (line[i] == '\n') i--;
	int length = i + 1;
	line[length] = '\0';

	for (i = 0, t = 0; i < length; ++i, ++t) {
		/// printf("%c\n", line[i]);
		if (line[i + 1] == '=') {
			char c1 = line[i], c2 = line[i + 3];
			if (islower(c1) && islower(c2)) {
				tokens[t].type = MATCH;
				tokens[t].var = c1 - 'a' + 1;
				tokens[t].other_var = c2 - 'a' + 1;
			} else if (!islower(c1) && !islower(c2)) {
				tokens[t].type = BOOL;
				tokens[t].b = (c1 == c2);
			} else {
				tokens[t].type = ASSIGN;
				if (islower(c1)) {
					tokens[t].var = c1 - 'a' + 1;
					tokens[t].b = c2;
				} else {
					tokens[t].var = c2 - 'a' + 1;
					tokens[t].b = c1;
				}
			}
			i += 3;
		} else if (line[i] == ':') {
			tokens[t].type = END;
		} else if (line[i] == '?') {
			tokens[t].type = Q;
		} else if (islower(line[i])) {
			tokens[t].type = VAR;
			tokens[t].var = line[i] - 'a' + 1;
		} else if (isdigit(line[i])) {
			tokens[t].type = BOOL;
			tokens[t].var = line[i] - 'a' + 1;
		} else assert(false);
	}
	tokens[t].type = END;

	// Set memory
	for (i = 1; i <= vars; ++i) {
		P[0][i] = i;
		B[0][i] = -1;
	}
	V[0] = 1;

	t = 0;
	d= 0;
	printf("%d\n", select());

	return 0;
}
