#include "pch.h"
#include "HV3DObjLoader.h"
#if __has_include("HV3DLoaders.HV3DObjLoader.g.cpp")
#include "HV3DLoaders.HV3DObjLoader.g.cpp"
#endif

using namespace std;

using namespace winrt;

using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Foundation::Collections;

using namespace winrt::Windows::Storage;

using namespace winrt::HV3DDUALITY;
using namespace winrt::HV3DDUALITY::HV3DTensors;

namespace winrt::HV3DLoaders::implementation
{
    IVector<HV3DTriangle> HV3DObjLoader::LoadMeshFromFile(hstring file)
    {
        string line;

        IVector<hstring> oFileBuffer = ReadFromObjAsync(std::wstring{ file });

        wofstream* oDebuggerFile = new wofstream[1];
            
        CreateDebugFileAsync(&oDebuggerFile, L"C:\\Users\\rebek\\Source\\DUALITY\\Debug.txt");

        for (UINT i = 0; i < oFileBuffer.Size(); i++)
        {
            WriteDebugFileAsync(&oDebuggerFile, std::to_wstring(i));

            wchar_t annotation0 = oFileBuffer.GetAt(i).data()[0];
            wchar_t annotation1 = oFileBuffer.GetAt(i).data()[1];

            switch (annotation0) {

            case '#':
                break;

            case 'o':
                number_of_objects += 1;
                break;

            case 'l':
                break;

            case 'v':
                switch (annotation1) {
                case ' ':
                    ExtractVertexFromLine(oFileBuffer.GetAt(i).c_str());
                    break;

                case 't':
                    ExtractTextCoordFromLine(oFileBuffer.GetAt(i).c_str());
                    break;

                case 'n':
                    ExtractVertexNormalFromLine(oFileBuffer.GetAt(i).c_str());
                    break;

                case 'p':
                    break;

                }
                break;

            case 'f':
                MakeFaces(oFileBuffer.GetAt(i).c_str());
                break;

            case 'm':
                break;

            case 'u':
                break;

            case 'n':
                break;

            }

        }

        return oInputBuffer;

    }

    void HV3DObjLoader::ExtractVertexFromLine(wstring l)
    {
        float xval = 0.0f;
        float yval = 0.0f;
        float zval = 0.0f;

        wstring l1 = l.substr(2, wstring::npos);

        size_t pos1 = l1.find(' ') + 1;

        wstring l2 = l1.substr(pos1, wstring::npos);

        size_t pos2 = l2.find(' ') + 1;

        wstring l3 = l2.substr(pos2, wstring::npos);

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

    void HV3DObjLoader::ExtractTextCoordFromLine(wstring l)
    {
        float uval = 0.0f;
        float vval = 0.0f;

        wstring l1 = l.substr(3, wstring::npos);

        size_t pos1 = l1.find(' ') + 1;

        wstring l2 = l1.substr(pos1, wstring::npos);

        uval = stof(l1.substr(0, pos1 - 1).c_str());

        vval = stof(l2.c_str());

        HV3DTextCoord oTextCoord{};
        oTextCoord.u = uval;
        oTextCoord.v = vval;

        oTextCoordList.push_back(oTextCoord);

        return;

    }

    void HV3DObjLoader::ExtractVertexNormalFromLine(wstring l)
    {
        float aval = 0.0f;
        float bval = 0.0f;
        float cval = 0.0f;

        wstring l1 = l.substr(3, wstring::npos);

        size_t pos1 = l1.find(' ') + 1;

        wstring l2 = l1.substr(pos1, wstring::npos);

        size_t pos2 = l2.find(' ') + 1;

        wstring l3 = l2.substr(pos2, wstring::npos);

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

    void HV3DObjLoader::MakeFaces(wstring l)
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
        wstring l1 = l.substr(2, wstring::npos);

        pos1 = l1.find(' ') + 1;

        wstring l2 = l1.substr(pos1, wstring::npos);

        pos2 = l2.find(' ') + 1;

        wstring l3 = l2.substr(pos2, wstring::npos);

        pos3 = l3.find(' ') + 1;

        wstring l4{ '\0' };
        if (pos3 != 0)
        {
            l4 = l3.substr(pos3, wstring::npos);
        }

        /*vertex 1*/
        wstring vl1 = l1.substr(0, pos1);

        div1 = vl1.find('/') + 1;

        wstring tl1 = vl1.substr(div1, pos1);

        div2 = tl1.find('/') + 1;

        wstring nl1 = tl1.substr(div2, pos1);

        vertex_coordA = stoi(vl1.substr(0, div1 - 1));

        text_coordA = stoi(tl1.substr(0, div2 - 1));

        normal_vectorA = stoi(nl1);

        /*vertex 2*/
        wstring vl2 = l2.substr(0, pos2);

        div1 = vl2.find('/') + 1;

        wstring tl2 = vl2.substr(div1, pos2);

        div2 = tl2.find('/') + 1;

        wstring nl2 = tl2.substr(div2, pos2);

        vertex_coordB = stoi(vl2.substr(0, div1 - 1));

        text_coordB = stoi(tl2.substr(0, div2 - 1));

        normal_vectorB = stoi(nl2);

        /*vertex 3*/
        if (pos3 != 0)
        {
            wstring vl3 = l3.substr(0, pos3);

            div1 = vl3.find('/') + 1;

            wstring tl3 = vl3.substr(div1, pos3);

            div2 = tl3.find('/') + 1;

            wstring nl3 = tl3.substr(div2, pos3);

            vertex_coordC = stoi(vl3.substr(0, div1 - 1));

            text_coordC = stoi(tl3.substr(0, div2 - 1));

            normal_vectorC = stoi(nl3);
        }
        else
        {
            wstring vl3 = l3.substr(0, wstring::npos);

            div1 = vl3.find('/') + 1;

            wstring tl3 = vl3.substr(div1, wstring::npos);

            div2 = tl3.find('/') + 1;

            wstring nl3 = tl3.substr(div2, wstring::npos);

            vertex_coordC = stoi(vl3.substr(0, div1 - 1));

            text_coordC = stoi(tl3.substr(0, div2 - 1));

            normal_vectorC = stoi(nl3);
        }

        if (*l4.c_str() == '\0')
        {
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

            oInputBuffer.Append(oTriangleA);
        }
        else
        {
            /*vertex 4*/
            wstring vl4 = l4.substr(0, wstring::npos);

            div1 = vl4.find('/') + 1;

            wstring tl4 = vl4.substr(div1, wstring::npos);

            div2 = tl4.find('/') + 1;

            wstring nl4 = tl4.substr(div2, wstring::npos);

            vertex_coordD = stoi(vl4.substr(0, div1 - 1));

            text_coordD = stoi(tl4.substr(0, div2 - 1));

            normal_vectorD = stoi(nl4);
            
            HV3DTriangle oTriangleA;
            oTriangleA.vert1.vcoord = oVertexCoordList.at(vertex_coordA - 1);
            oTriangleA.vert1.tcoord = oTextCoordList.at(text_coordA - 1);
            oTriangleA.vert1.normal = oVertexNormalList.at(normal_vectorA - 1);
            oTriangleA.vert2.vcoord = oVertexCoordList.at(vertex_coordB - 1);
            oTriangleA.vert2.tcoord = oTextCoordList.at(text_coordB - 1);
            oTriangleA.vert2.normal = oVertexNormalList.at(normal_vectorB - 1);
            oTriangleA.vert3.vcoord = oVertexCoordList.at(vertex_coordD - 1);
            oTriangleA.vert3.tcoord = oTextCoordList.at(text_coordD - 1);
            oTriangleA.vert3.normal = oVertexNormalList.at(normal_vectorD - 1);

            oInputBuffer.Append(oTriangleA);

            HV3DTriangle oTriangleB;
            oTriangleB.vert1.vcoord = oVertexCoordList.at(vertex_coordB - 1);
            oTriangleB.vert1.tcoord = oTextCoordList.at(text_coordB - 1);
            oTriangleB.vert1.normal = oVertexNormalList.at(normal_vectorB - 1);
            oTriangleB.vert2.vcoord = oVertexCoordList.at(vertex_coordC - 1);
            oTriangleB.vert2.tcoord = oTextCoordList.at(text_coordC - 1);
            oTriangleB.vert2.normal = oVertexNormalList.at(normal_vectorC - 1);
            oTriangleB.vert3.vcoord = oVertexCoordList.at(vertex_coordD - 1);
            oTriangleB.vert3.tcoord = oTextCoordList.at(text_coordD - 1);
            oTriangleB.vert3.normal = oVertexNormalList.at(normal_vectorD - 1);

            oInputBuffer.Append(oTriangleB);

        };

        return;

    }

    IVector<hstring> HV3DObjLoader::ReadFromObjAsync(wstring file)
    {
        IVector<hstring> oFile{ winrt::single_threaded_vector<hstring>() };

        wifstream oBufferIn{ file, std::ios::out };

        wstring line;
        while (getline(oBufferIn, line))
        {
            oFile.Append(line);

        }

        return oFile;

    }

    void HV3DObjLoader::CreateDebugFileAsync(std::wofstream** buffer, wstring file)
    {
        *buffer = new wofstream();

        (*buffer)->open(file, ios::out | ios::trunc);

        if ((*buffer)->is_open() != true)
        {
            winrt::throw_last_error();

        }

        return;

    }

    void HV3DObjLoader::WriteDebugFileAsync(wofstream** out, wstring line)
    {
        (*out)->write(line.c_str(), line.size());


        return;

    }

}
