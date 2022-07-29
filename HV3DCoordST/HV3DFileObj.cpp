#include "pch.h"
#include "HV3DFileObj.h"
#if __has_include("HV3DFileObj.g.cpp")
#include "HV3DFileObj.g.cpp"
#endif

using namespace std;

using namespace winrt;

using namespace winrt::HV3DDUALITY;
using namespace winrt::HV3DDUALITY::HV3DTensors;

namespace winrt::HV3DCoordST::implementation
{
    vector<std::string> file{};

    int32_t obj_object{ -1 };

    int error_line{ 0 };

	void HV3DFileObj::LoadMeshFromFile()
	{
        string filename("C:\\Users\\rebek\\ARCHIVE\\Entangled Logic Venture Co\\Latrodectus H RRC\\Latrodectus H RRC.obj");
        
        ifstream input_file{};
        input_file.open(filename.c_str(), ios::in);
        
        string test("C:\\Users\\rebek\\source\\DUALITY\\test.txt");

        ofstream output_file{};
        output_file.open(test, std::ofstream::out | std::ofstream::trunc);
        
        string line;

        if (!input_file.is_open()) 
        { 
            winrt::throw_last_error(); 
        
        };

        while (getline(input_file, line)) 
        {
            file.push_back(line);

        }        

        for (int i = 0; i < file.size(); i++) {

            error_line = i;
            if (error_line == 199252)
            {
                bool berror = true;

            }

            output_file.seekp(0);
            output_file.write("            ", 12);
            output_file.seekp(0);
            output_file.write(std::to_string(i).c_str(),
                std::to_string(i).length());

            wchar_t annotation0 = file.at(i).at(0);
            wchar_t annotation1 = file.at(i).at(1);

            switch (annotation0) {
            
            case '#':
                break;

            case 'o':
                obj_object += 1;
                break;

            case 'l':
                break;

            case 'v': 
                switch (annotation1) {
                case ' ':
                    ExtractVertexFromLine(file.at(i));
                    break;

                case 't':
                    ExtractTextCoordFromLine(file.at(i));
                    break;

                case 'n':
                    ExtractVertexNormalFromLine(file.at(i));
                    break;

                case 'p':
                    break;

                }
                break;

            case 'f':
                MakeFaces(file.at(i));
                break;

            case 'm':
                break;

            case 'u':
                break;

            case 'n':
                break;
            
            }

        }
                
        input_file.close();
        output_file.close();
        
		return;

	}

    void HV3DFileObj::ExtractVertexFromLine(string l)
    {
        float xval = 0.0f;
        float yval = 0.0f;
        float zval = 0.0f;

        string l1 = l.substr(2, string::npos);

        size_t pos1 = l1.find(' ') + 1;
        
        string l2 = l1.substr(pos1, string::npos);
        
        size_t pos2 = l2.find(' ') + 1;

        string l3 = l2.substr(pos2, string::npos);

        xval = stof(l1.substr(0, pos1 - 1).c_str());

        yval = stof(l2.substr(0, pos2 - 1).c_str());

        zval = stof(l3.c_str());

        HV3DVertexCoord oVertexCoord{};
        oVertexCoord.x = xval;
        oVertexCoord.y = yval;
        oVertexCoord.z = zval;

        oVertexCoordList.push_back(oVertexCoord);

        return;

    }

    void HV3DFileObj::ExtractTextCoordFromLine(string l)
    {
        float uval = 0.0f;
        float vval = 0.0f;

        string l1 = l.substr(3, string::npos);

        size_t pos1 = l1.find(' ') + 1;

        string l2 = l1.substr(pos1, string::npos);

        uval = stof(l1.substr(0, pos1 - 1).c_str());

        vval = stof(l2.c_str());

        HV3DTextCoord oTextCoord{};
        oTextCoord.u = uval;
        oTextCoord.v = vval;

        oTextCoordList.push_back(oTextCoord);

        return;

    }

    void HV3DFileObj::ExtractVertexNormalFromLine(string l)
    {
        float aval = 0.0f;
        float bval = 0.0f;
        float cval = 0.0f;

        string l1 = l.substr(3, string::npos);

        size_t pos1 = l1.find(' ') + 1;

        string l2 = l1.substr(pos1, string::npos);

        size_t pos2 = l2.find(' ') + 1;

        string l3 = l2.substr(pos2, string::npos);

        aval = stof(l1.substr(0, pos1 - 1).c_str());

        bval = stof(l2.substr(0, pos2 - 1).c_str());

        cval = stof(l3.c_str());

        HV3DVertexNormal oVertexNormal{};
        oVertexNormal.a = aval;
        oVertexNormal.b = bval;
        oVertexNormal.c = cval;

        oVertexNormalList.push_back(oVertexNormal);

        return;

    }

    void HV3DFileObj::MakeFaces(std::string l)
    {
        size_t pos1{ 0 };
        size_t pos2{ 0 };
        size_t pos3{ 0 };

        size_t div1{ 0 };
        size_t div2{ 0 };

        int32_t vertex_coordA{ 0 };
        int32_t vertex_coordB{ 0 };
        int32_t vertex_coordC{ 0 };
        int32_t vertex_coordD{ 0 };
        
        int32_t text_coordA{ 0 };
        int32_t text_coordB{ 0 };
        int32_t text_coordC{ 0 };
        int32_t text_coordD{ 0 };

        int32_t normal_vectorA{ 0 };
        int32_t normal_vectorB{ 0 };
        int32_t normal_vectorC{ 0 };
        int32_t normal_vectorD{ 0 };
        
        /*split string*/
        string l1 = l.substr(2, string::npos);

        pos1 = l1.find(' ') + 1;

        string l2 = l1.substr(pos1, string::npos);

        pos2 = l2.find(' ') + 1;

        string l3 = l2.substr(pos2, string::npos);

        pos3 = l3.find(' ') + 1;

        string l4 = l3.substr(pos3, string::npos);

        /*vertex 1*/
        string vl1 = l1.substr(0, pos1);

        div1 = vl1.find('/') + 1;

        string tl1 = vl1.substr(div1, pos1);

        div2 = tl1.find('/') + 1;

        string nl1 = tl1.substr(div2, pos1);

        vertex_coordA = stoi(vl1.substr(0, div1 - 1));

        text_coordA = stoi(tl1.substr(0, div2 - 1));
        
        normal_vectorA = stoi(nl1);
       
        /*vertex 2*/
        string vl2 = l2.substr(0, pos2);

        div1 = vl2.find('/') + 1;

        string tl2 = vl2.substr(div1, pos2);

        div2 = tl2.find('/') + 1;

        string nl2 = tl2.substr(div2, pos2);

        vertex_coordB = stoi(vl2.substr(0, div1 - 1));

        text_coordB = stoi(tl2.substr(0, div2 - 1));

        normal_vectorB = stoi(nl2);
                
        /*vertex 3*/
        string vl3 = l3.substr(0, pos3);

        div1 = vl3.find('/') + 1;

        string tl3 = vl3.substr(div1, pos3);

        div2 = tl3.find('/') + 1;

        string nl3 = tl3.substr(div2, pos3);

        vertex_coordC = stoi(vl3.substr(0, div1 - 1));

        text_coordC = stoi(tl3.substr(0, div2 - 1));

        normal_vectorC = stoi(nl3);

        HV3DTriangle oTriangleA;
        oTriangleA.vert1.vcoord = oVertexCoordList.at(vertex_coordA - 1);
        oTriangleA.vert1.tcoord = oTextCoordList.at(text_coordA - 1);
        oTriangleA.vert1.normal = oVertexNormalList.at(normal_vectorA - 1);
        oTriangleA.vert2.vcoord = oVertexCoordList.at(vertex_coordB - 1);
        oTriangleA.vert2.tcoord = oTextCoordList.at(text_coordB - 1);
        oTriangleA.vert2.normal = oVertexNormalList.at(normal_vectorB - 1);
        oTriangleA.vert3.vcoord = oVertexCoordList.at(vertex_coordC - 1);
        oTriangleA.vert3.tcoord = oTextCoordList.at(text_coordC - 1);
        oTriangleA.vert3.normal = oVertexNormalList.at(normal_vectorC - 1);

        oInputBuffer.push_back(oTriangleA);

        if (*l4.c_str() != '\0')
        {
            /*vertex 4*/
            string vl4 = l4.substr(0, string::npos);

            div1 = vl4.find('/') + 1;

            string tl4 = vl4.substr(div1, string::npos);

            div2 = tl4.find('/') + 1;

            string nl4 = tl4.substr(div2, string::npos);

            vertex_coordD = stoi(vl4.substr(0, div1 - 1));

            text_coordD = stoi(tl4.substr(0, div2 - 1));

            normal_vectorD = stoi(nl4);

            HV3DTriangle oTriangleB;
            oTriangleB.vert1.vcoord = oVertexCoordList.at(vertex_coordC - 1);
            oTriangleB.vert1.tcoord = oTextCoordList.at(text_coordC - 1);
            oTriangleB.vert1.normal = oVertexNormalList.at(normal_vectorC - 1);
            oTriangleB.vert2.vcoord = oVertexCoordList.at(vertex_coordD - 1);
            oTriangleB.vert2.tcoord = oTextCoordList.at(text_coordD - 1);
            oTriangleB.vert2.normal = oVertexNormalList.at(normal_vectorD - 1);
            oTriangleB.vert3.vcoord = oVertexCoordList.at(vertex_coordB - 1);
            oTriangleB.vert3.tcoord = oTextCoordList.at(text_coordB - 1);
            oTriangleB.vert3.normal = oVertexNormalList.at(normal_vectorB - 1);

            oInputBuffer.push_back(oTriangleB);

        }

        return;

    }

}
