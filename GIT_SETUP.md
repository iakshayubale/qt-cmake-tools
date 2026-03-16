# Git Repository Setup Guide

## Quick Start

To initialize the Qt CMake Tools repository with Git:

```bash
cd qt-cmake-tools

# Initialize git repository
git init

# Add all files
git add .

# Create initial commit
git commit -m "Initial commit: Qt CMake Tools v1.0.0

- Add QtAutoDeploy CMake module
- Add QtAutoQmlModule CMake module  
- Add QtSetupProject CMake module
- Add QtUtils CMake module
- Create example projects (console, widget, QML)
- Add comprehensive documentation
- Add unit tests
- Add MIT License"

# Set origin
git remote add origin https://github.com/iakshayubale/qt-cmake-tools.git

# Create main branch and push
git branch -M main
git push -u origin main
```

## Repository Configuration

### Configure Git User (First Time Only)

```bash
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
```

### Local Repository Configuration

```bash
cd qt-cmake-tools
git config user.name "Your Name"
git config user.email "your.email@example.com"
```

## Repository URL

```bash
git remote set-url origin https://github.com/iakshayubale/qt-cmake-tools.git
```

## Branching Strategy

### Main Branches

- **main** - Production-ready code
- **develop** - Development branch for next release

### Feature Branches

```bash
# Create feature branch
git checkout -b feature/new-feature

# When done, create pull request to develop
git push origin feature/new-feature
```

### Release Branches

```bash
# Create release branch
git checkout -b release/1.0.0 develop

# Bump version, merge to main and develop
git merge --no-ff release/1.0.0 main
git merge --no-ff release/1.0.0 develop
```

## Commit Guidelines

Follow [Conventional Commits](https://www.conventionalcommits.org/):

```
<type>[optional scope]: <description>

[optional body]

[optional footer(s)]
```

### Types

- **feat**: A new feature
- **fix**: A bug fix
- **docs**: Documentation changes
- **style**: Code style changes (formatting, missing semicolons, etc)
- **refactor**: Code refactoring without feature changes
- **perf**: Performance improvements
- **test**: Test additions or changes
- **chore**: Build system, dependency updates, etc

### Examples

```bash
git commit -m "feat: add qt_auto_deploy function"
git commit -m "fix: handle Qt5 plugin paths correctly"
git commit -m "docs: add API reference"
git commit -m "chore: update dependencies"
```

## Tagging Releases

```bash
# Create annotated tag
git tag -a v1.0.0 -m "Release version 1.0.0"

# Push tags to remote
git push origin v1.0.0

# Or push all tags
git push origin --tags
```

## GitHub Setup

### 1. Create Repository

1. Go to https://github.com/new
2. Name: `qt-cmake-tools`
3. Description: "Modern CMake utilities for Qt 6 projects"
4. Choose Public (for open source)
5. Click "Create repository"

### 2. Set Origin

```bash
git remote add origin https://github.com/iakshayubale/qt-cmake-tools.git
git branch -M main
git push -u origin main
```

### 3. Enable Features

In GitHub repository settings:

- **Discussions**: Enable for community
- **Projects**: Enable for tracking
- **Releases**: Enable for version management
- **Branch protection**: Require pull request reviews before merging to main

### 4. Add Collaborators

Settings → Collaborators → Add people

### 5. Create GitHub Actions (CI/CD)

Create `.github/workflows/cmake.yml`:

```yaml
name: CMake Build and Test

on: [push, pull_request]

jobs:
  build:
    runs-on: ${{ matrix.os }}
    strategy:
      matrix:
        os: [ubuntu-latest, windows-latest, macos-latest]
        qt-version: ['6.5.0']
    
    steps:
    - uses: actions/checkout@v3
    
    - name: Install Qt
      uses: jurplel/install-qt-action@v3
      with:
        version: ${{ matrix.qt-version }}
    
    - name: Configure
      run: |
        mkdir build
        cd build
        cmake .. -DCMAKE_PREFIX_PATH=$Qt6_DIR
    
    - name: Build
      run: cmake --build build --config Release
    
    - name: Test
      run: cd build && ctest --output-on-failure
```

## Pre-Push Checklist

Before pushing code:

- [ ] All tests pass: `ctest --output-on-failure`
- [ ] All examples build successfully
- [ ] Documentation is updated
- [ ] Commit messages follow conventions
- [ ] No sensitive data in code
- [ ] Code follows style guidelines

## .gitignore

The repository includes `.gitignore` with:

- Build directories
- IDE files
- Temporary files
- Platform-specific files

No additional configuration needed!

## Useful Git Commands

```bash
# View commit history
git log --oneline

# View changes
git diff

# Stage specific file
git add path/to/file

# Unstage file
git reset path/to/file

# View branch info
git branch -v

# Switch branch
git checkout branch-name

# Create and switch
git checkout -b new-branch

# Merge branch
git merge branch-name

# Delete branch
git branch -d branch-name

# Push all branches
git push origin --all

# Pull latest changes
git pull origin main
```

## Collaboration Workflow

1. **Create feature branch**: `git checkout -b feature/your-feature`
2. **Make changes**: Edit files
3. **Commit changes**: `git commit -m "commit message"`
4. **Push to GitHub**: `git push origin feature/your-feature`
5. **Create Pull Request**: On GitHub, request merge to develop
6. **Code review**: Wait for approval
7. **Merge**: Merge to develop, then review for main

## Making First Release

```bash
# Update version numbers in files
# - README.md
# - cmake/QtAutoDeploy.cmake (as comments)
# - docs/GETTING_STARTED.md

# Update CHANGELOG.md with release notes

# Commit version changes
git add .
git commit -m "chore: bump version to 1.0.0"

# Create tag
git tag -a v1.0.0 -m "Release version 1.0.0"

# Push tag
git push origin v1.0.0

# GitHub automatically creates release from tag
```

## Repository Health

### README Stats

Add to your README:

```markdown
![GitHub stars](https://img.shields.io/github/stars/iakshayubale/qt-cmake-tools)
![GitHub license](https://img.shields.io/github/license/iakshayubale/qt-cmake-tools)
![GitHub release](https://img.shields.io/github/v/release/iakshayubale/qt-cmake-tools)
```

### Badges

```markdown
[![CMake](https://img.shields.io/badge/CMake-3.16+-blue)](https://cmake.org/)
[![Qt](https://img.shields.io/badge/Qt-6.5+-green)](https://qt.io/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Build Status](https://github.com/iakshayubale/qt-cmake-tools/workflows/CMake/badge.svg)](https://github.com/iakshayubale/qt-cmake-tools/actions)
```

## Support for Repository

- **Star** the repository if you find it useful
- **Fork** to contribute
- **Watch** to stay informed of updates
- **Share** with others who might benefit

