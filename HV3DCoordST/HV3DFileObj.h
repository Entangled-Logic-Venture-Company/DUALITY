#pragma once

#include "winrt/HV3DDUALITY.HV3DTensors.h"

#include "HV3DFileObj.g.h"

namespace winrt::HV3DCoordST::implementation
{
    struct HV3DFileObj : HV3DFileObjT<HV3DFileObj>
    {
    public:
        HV3DFileObj() = default;

        void LoadMeshFromFile();

    private:
        void ExtractVertexFromLine(std::string);
        void ExtractTextCoordFromLine(std::string);
        void ExtractVertexNormalFromLine(std::string);
        void MakeFaces(std::string);

        std::vector<HV3DDUALITY::HV3DTensors::HV3DVertexCoord> oVertexCoordList{};
        std::vector<HV3DDUALITY::HV3DTensors::HV3DTextCoord> oTextCoordList{};
        std::vector<HV3DDUALITY::HV3DTensors::HV3DVertexNormal> oVertexNormalList{};
        std::vector<HV3DDUALITY::HV3DTensors::HV3DTriangle> oInputBuffer{};

    };

}

namespace winrt::HV3DCoordST::factory_implementation
{
    struct HV3DFileObj : HV3DFileObjT<HV3DFileObj, implementation::HV3DFileObj>
    {

    };

}
