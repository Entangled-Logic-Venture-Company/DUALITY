#pragma once

#include <winrt/Windows.Storage.h>

#include "winrt/HV3DDUALITY.HV3DTensors.h"

#include "Generated Files/HV3DLoaders.HV3DObjLoader.g.h"

namespace winrt::HV3DLoaders::implementation
{
    struct HV3DObjLoader : HV3DObjLoaderT<HV3DObjLoader>
    {
    public:
        HV3DObjLoader() = default;

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

namespace winrt::HV3DLoaders::factory_implementation
{
    struct HV3DObjLoader : HV3DObjLoaderT<HV3DObjLoader, implementation::HV3DObjLoader>
    {

    };

}
