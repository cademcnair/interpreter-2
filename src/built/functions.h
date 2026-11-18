using namespace Lang::Values;

namespace Lang {
    namespace Built {
        namespace Functions {
            ComplexValue *print(vector<ComplexValue*> params) {
                if (params.size() != 1) __error("Can only print with one param");
                ComplexValue *printing = params[0];
                if (printing->index() != 0) __error("Can only print strings, numbers, and booleans");
                if (printing->get0().index() == 0) cout << get<0>(printing->get0()) << endl;
                if (printing->get0().index() == 1) cout << get<1>(printing->get0()) << endl;
                if (printing->get0().index() == 2) cout << get<2>(printing->get0()) << endl;
                return new ComplexValue(nullptr);
            }
        }
    }
}