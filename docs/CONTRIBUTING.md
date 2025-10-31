# Contributing to the C Track

Thank you for interest in contributing to the Exercism C language track!
All contributions are welcome, be it a new exercise, a change to the tooling or documentation, a raised issue or even just a comment on an existing issue or PR.
This file provides information to help you get started.

Firstly, have a read of the [Exercism docs][], specifically the information on [contributing to a language track][], as these documents cover a lot of the basic information.

Subsequently note that there are a few things specific to this repository that are explained below.

We encourage contributions that provide fixes and improvements to existing exercises.
Please note that this track's exercises must conform to the standards determined in the [problem-specifications][] repository.
Changes to the tests or documentation of a common exercise will often warrant a pull request in that repository before it can be incorporated into this track's exercises.
If you're unsure, then go ahead and open a GitHub [issue][], and we'll discuss the change.

## Code of Conduct

Help us keep Exercism welcoming.
Please read and abide by the [Code of Conduct][].

## Git Workflow

1. Fork and clone.
2. Add this repository as a new remote to your clone: `git remote add upstream https://github.com/exercism/c.git`
3. Create a new branch: `git checkout -b name-of-branch`
4. Commit and push as usual on your new branch
5. When you're ready to submit a pull request, rebase your branch onto the upstream main so that you can resolve any conflicts: `git fetch upstream && git rebase upstream/main` You may need to push up to your branch using `--force` after resolving conflicts.
6. When you've got everything ready, push up to your branch and create the pull request as outlined below.

## Issues

We keep track of bugs, enhancements and support requests in the repository using GitHub [issues][].

For higher-level discussions about the project as a whole, check out the issues in the [discussions][] repository.

### Good First Patch

We're trying to label issues with "good first patch" if we think that these can be solved without too much context about Exercism's codebase or functionality. To find them, you can do a search for [good-first-patch][].

## Pull Requests

It would be awesome if you follow these simple [pull request guidelines][] while creating your PR, but it isn't required.

Pull requests should be focused on a single, issue or change.
We welcome changes to code style and wording but please open a separate PR for these changes if possible.
Please open an issue before creating a PR that makes significant (breaking) changes to an existing exercise or makes changes across many exercises. It is best to discuss these changes before doing the work.

If your change is to an exercise you can run the CI scripts before submitting the pull request, or they will be automatically run after, as described in [Continuous Integration][].

When submitting a pull request, sometimes we will ask you to make changes before we accept the patch.

Please do not close the first pull request and open a second one with these changes.
If you push more commits to a branch that you've opened a pull request for, it automatically updates the pull request.

If you want to create a PR with changes that aren't quite ready to be merged to main yet (maybe you would like to discuss some particular item, for example), create the PR as normal but use the GitHub website interface to [convert the PR to a draft][] so that maintainers know that it isn't quite ready to be merged just yet.

As with adding more commits, you do not need to close your pull request and open a new one if you change the history (rebase, squash, amend), and use git push --force to update the branch on your fork.
The pull request points to that branch, not to specific commits.

## Coding Style

The code style expected for code change contributions is explained in the [style guide][].

The exercise code is checked during [CI][Continuous Integration] for conformance to the spacing and indentation style rules.
The check uses the [`clang-format`][clang-format] CLI tool.
When adding or making a change to an exercise, you can check that your change conforms to these rules by running the tool locally before committing.

On Linux `clang-format` should be available for install via your distribution's package manager.
On a Mac you can install the package `clang-format` using [Homebrew][].

clang-format can be run on all files by executing `format.sh`.
To manually run it on a single file, you can execute the following:

```bash
clang-format -i $(file)
```

## Exercise anatomy

Each exercise should be contained in a directory `c/exercises/practice/{exercise-name}`.
See [implement-an-exercise-from-specification][] for in depth details on implementing an exercise that matches the specification

The structure of an exercise directory is as follows (note the differing hyphen and underscore usage for directory names and file names respectively):

```text
+-- {exercise-name}
    +-- makefile
    +-- srcs
    |   +-- {exercise-name}.c
    |   +-- {exercise-name}.h
    +-- test
    |   +-- test_{exercise-name}.c
    |    +-- test-framework
    |        +-- unity.c
    |        +-- unity.h
    |        +-- unity_internals.h
```

* `test` - contains the test file `test_{exercise_name}.c` and a `test-framework` directory containing the test harness [Unity][] from [ThrowTheSwitch][].
  ThrowTheSwitch has a decent guide on [getting started with Unity][] should you desire a tutorial.
  The version of Unity used is indicated in [versions][]. The layout of the test file is described in the [style guide][test-file-layout].
  Tests should be written that satisfy `canonical-data.json` file for the exercise in the [problem-specifications][] repository
* `srcs` - contains the source files `{exercise-name}.c` and `[exercise-name].h`.
  Please use [include guards][] in your header files.
  The exercise tests can be run using `make test` from the repository root.
* `makefile` - is the makefile for the exercise as it would build.
Two rules are required,  
test: compile test_{exercise-name}.c and run it.
memcheck: compile test_{exercise-name} with -fsanitize=addres, -fno-common, -fno-omit-frame-pointer flag and run it
Makefiles are expected to change very little between exercises so it should be easy to copy one from another exercise.

**Don't forget** to add the exercise to the track's `config.json`. For this you will need to determine the best place to add the exercise within the order of all other track exercises. You will also need to generate a UUID to add here. For both of these tasks you can use the [configlet][] tool; the tool will even lint and format the `config.json` for you after you've made these changes!

FYI - to get the install artifact for the configlet tool, checkout the [configlet releases page][].

## Continuous Integration

This repository uses GitHub workflows to run some tools on each commit to a pull request.
The simplest way to run these workflows on your own contribution is to open a PR on this repository with your changes, set the PR as a draft, then allow this repository's CI setup to take care of things for you automatically.

### CI environment

GitHub runs the CI on virtual machines it refers to as [hosted runners][].
Workflows can configure some aspects of the runners they would like to be run on.

The workflows in this repository specify only that they each should be run on Ubuntu 24.04. The workflows are pinned to specific versions rather than refer to `latest` as some tools used can perform differently on different versions.

### Run CI on Your Own Fork

If you would like, it is also possible to run the CI on your own fork, simply clone this repository as normal on GitHub.
The YAML files located in [`./.github/workflows/`][workflows] should work just the same.
If you would like the [`/format`][format-workflow] automated action to work correctly, you will need to add a deploy key to your cloned repository.

### The Workflows

* `checks.yml` runs `shellcheck` on the tool scripts and subsequently runs the following of those tools:
  * `./bin/check-unitybegin`
  * `./bin/verify-unity-version`
  * `./bin/check-include-guards`
  * [Lychee link checker][lychee] action
* `configlet.yml` fetches the latest version of configlet from which it then runs the `lint` command on the track
* `format-code.yml` checks for the string `/format` within any comment on a PR, if it finds it then `format.sh` is run on the exercises and any resulting changes are committed. A deploy key is required for the commit to be able to re-trigger CI. The deploy key is administered by Exercism directly.
* `test.yml` runs `make` in the repository root to test all exercises

### The Tools

You can see from the [workflows][] that GitHub is instructed to run tools from the [`./bin`][bin] directory.
The work the tools in this directory perform is described as follows:

* `check-unitybegin` ensures that every test file correctly adds the `UNITY_BEGIN()` line at the start of its `main()` function.
* `fetch-configlet` fetches the `configlet` tool from its [repository][configlet].
* `verify-unity-version` checks the version of the Unity test framework used by every exercise. The version this file should check for is specified in [`./docs/VERSIONS.md`][versions]
* `check-include-guards` checks that the include guards used in each exercises stub and example header are using the correct format, as follows:

    ```c
    #ifndef {EXERCISE_NAME}_H
    #define {EXERCISE_NAME}_H
    ```

* `fetch-configlet` fetches the `configlet` tool from its [repository][configlet].

### Run Tools Locally

You can also run individual tools on your own machine before committing.
Firstly make sure you have the necessary applications installed (such as `clang-format`, [`git`][git], [`sed`][sed], [`make`][make] and a C compiler), and then run the required tool from the repository root. For example:

```bash
~/git/c$ make
```

If you'd like to run only some of the tests to check your work, you can specify them as targets to make.

```bash
~/git/c$ make acronym all-your-base allergies
```

## Test Runner

This track has a test runner for Exercism v3!
You can check it out [here][c-test-runner].

Test runners provide a docker-ised method to run an exercise's tests against a students code in Exercism v3.
This Docker approach helps to allow in-browser coding by students.
Read more about [test runners].

[Exercism docs]: https://github.com/exercism/docs
[contributing to a language track]: https://github.com/exercism/docs/tree/main/building
[problem-specifications]: https://github.com/exercism/problem-specifications
[issue]: ./CONTRIBUTING.md#issues
[Code of Conduct]: https://exercism.io/code-of-conduct
[issues]: https://github.com/exercism/c/issues
[discussions]: https://github.com/exercism/discussions/issues
[good-first-patch]: https://github.com/exercism/c/labels/good%20first%20patch
[pull request guidelines]: https://github.com/exercism/docs/blob/main/building/github/contributors-pull-request-guide.md
[Continuous Integration]: ./CONTRIBUTING.md#continuous-integration
[convert the PR to a draft]: https://github.blog/changelog/2020-04-08-convert-pull-request-to-draft/
[style guide]: ./C_STYLE_GUIDE.md
[clang-format]: https://releases.llvm.org/10.0.0/tools/clang/docs/ClangFormat.html
[Homebrew]: https://brew.sh
[implement-an-exercise-from-specification]: https://github.com/exercism/docs/blob/main/building/tracks/practice-exercises/add.md
[Unity]: http://www.throwtheswitch.org/unity/
[ThrowTheSwitch]: http://www.throwtheswitch.org/#intro-1-section
[getting started with unity]: http://www.throwtheswitch.org/getting-started-with-unity/
[versions]: ./VERSIONS.md
[test-file-layout]: ./C_STYLE_GUIDE.md#test-file-layout
[include guards]: https://en.wikipedia.org/wiki/Include_guard
[configlet]: https://github.com/exercism/configlet
[configlet releases page]: https://github.com/exercism/configlet/releases
[hosted runners]: https://docs.github.com/en/actions/using-github-hosted-runners/about-github-hosted-runners
[actions/virtual-environments#1816]: https://github.com/actions/virtual-environments/issues/1816
[workflows]: ../.github/workflows/
[lychee]: https://github.com/lycheeverse/lychee-action
[bin]: ../bin
[format-workflow]: ../.github/workflows/format-code.yml
[git]: https://git-scm.com/
[sed]: https://www.gnu.org/software/sed/manual/sed.html
[make]: https://www.gnu.org/software/make/
[c-test-runner]: https://github.com/exercism/c-test-runner
[test runners]: https://github.com/exercism/docs/blob/main/building/tooling/test-runners/README.md
