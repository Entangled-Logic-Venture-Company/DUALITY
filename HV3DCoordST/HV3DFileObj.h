﻿#pragma once

#include "winrt/HV3DDUALITY.HV3DTensors.h"

#include "HV3DFileObj.g.h"

namespace winrt::HV3DCoordST::implementation
{
    struct HV3DFileObj : HV3DFileObjT<HV3DFileObj>
    {
    public:
        HV3DFileObj() = default;

        virtual Windows::Foundation::Collections::IVector<HV3DDUALITY::HV3DTensors::HV3DTriangle>
            LoadMeshFromFile(hstring);

    private:
        void ExtractVertexFromLine(std::wstring);
        void ExtractTextCoordFromLine(std::wstring);
        void ExtractVertexNormalFromLine(std::wstring);
        void MakeFaces(std::wstring);

        std::vector<HV3DDUALITY::HV3DTensors::HV3DVertexCoord> oVertexCoordList{};
        std::vector<HV3DDUALITY::HV3DTensors::HV3DTextCoord> oTextCoordList{};
        std::vector<HV3DDUALITY::HV3DTensors::HV3DVertexNormal> oVertexNormalList{};

        Windows::Foundation::Collections::IVector<HV3DDUALITY::HV3DTensors::HV3DTriangle> oInputBuffer{
            winrt::single_threaded_vector<HV3DDUALITY::HV3DTensors::HV3DTriangle>() };

        UINT number_of_objects{ 0 };

    private:
        Windows::Foundation::Collections::IVector<hstring> ReadFromObjAsync(std::wstring);

        void CreateDebugFileAsync(std::wofstream**, std::wstring);

        void WriteDebugFileAsync(std::wofstream**, std::wstring);
    };

}

namespace winrt::HV3DCoordST::factory_implementation
{
    struct HV3DFileObj : HV3DFileObjT<HV3DFileObj, implementation::HV3DFileObj>
    {

    };

}
